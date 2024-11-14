// Sistema de irrigação automatizado - por Paula Ferreira, 2024.

#include <EEPROM.h> // Biblioteca para armazenar dados na EEPROM.
#include <Wire.h> // Conexão do LCD.
#include <LiquidCrystal_I2C_Hangul.h> // Biblioteca do LCD.
#include <RTClib.h> // Biblioteca para RTC.
#include <DHT.h> // Bibliotea do DHT.
#include <DHT_U.h>

// Informações do DHT
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Informações do sensor CS12
#define SOIL_MOISTURE A3

// Numero de colunas, linhas e endereço do LCD.
#define col 16
#define lin 2
#define ende 0x27

// Endereço I2C do LCD e tamanho das colunas e linhas.

LiquidCrystal_I2C_Hangul lcd(0x27, 16, 2);

// Informações do RTC
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};

// Informações da bomba d'água e relé
const int bomba = 2;
const int rele = 3;

void setup() {

  Wire.begin();
  Serial.begin(9600);

  lcd.init();
  lcd.print("Inicializando...");
  delay(2000);
  lcd.clear();

  dht.begin();

  pinMode(bomba, OUTPUT);
  pinMode(rele, OUTPUT);

  if(! rtc.begin()) {
    lcd.print("Erro no relogio!"); 
    while(1);
  }

  if(rtc.lostPower()){ 
    lcd.print("Ajustando relogio"); 
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  delay(100);
}

void loop() {
  DateTime now = rtc.now();
  int hora = now.hour();

  lcd.setBacklight(HIGH);
  lcd.clear();

  //Leitura do DHT11
  int umidadeAr = dht.readHumidity();
  int temperatura = dht.readTemperature();

  //Leitura do sensor de umidade do solo
  int leituraSolo = analogRead(SOIL_MOISTURE);
  float umidadeSolo = map(leituraSolo, 0, 1023, 0, 100); // Conversão para porcentagem

  if (hora == 6 || hora == 9 || hora == 12 || hora == 15) {
    if (isnan(temperatura) || isnan(umidadeAr)) {
      lcd.print("Falha na leitura");
    } else {
      lcd.setCursor(2, 0);
      lcd.print("Ar: ");
      lcd.print(umidadeAr);
      lcd.print("%");

      lcd.setCursor(2,1);
      lcd.print("Solo: ");
      lcd.print(umidadeSolo);
      lcd.print("%");
      
      lcd.setCursor(2, 0);
      lcd.print("Temp: ");
      lcd.print(temperatura);
      lcd.print(" C");

    // Controle da bomba e do relé
  if (umidadeSolo <= 40) {  // Se a umidade for menor ou igual a 40%, liga a bomba
      lcd.setCursor(2, 0);
      lcd.print("Irrigando...");
      digitalWrite(rele, HIGH);   // Liga o relé
      digitalWrite(bomba, HIGH);  // Liga a bomba
      delay(60000);  // Aguarda 1 minuto

  // Desliga a bomba e o relé após 1 minuto
      lcd.setCursor(0, 0);
      lcd.print("Bomba: DESLIGADA");
      digitalWrite(rele, LOW);
      digitalWrite(bomba, LOW);
    } else {
  // Se a umidade não for maior que 40%, a bomba e o relé permanecem desligados
      lcd.setCursor(0, 0);
      lcd.print("Bomba: DESLIGADA");
      digitalWrite(rele, LOW);
      digitalWrite(bomba, LOW);
}

delay(3600000);

    }
  }
}
