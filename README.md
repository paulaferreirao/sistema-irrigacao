# PROPOSTA DE AUTOMAÇÃO DE UM SISTEMA DE IRRIGAÇÃO NO SEMIÁRIDO BRASILEIRO UTILIZANDO UMA PLACA DE PROTOTIPAGEM #
Para a idealização do sistema de irrigação, utilizou-se o Arduino UNO.
Os sensores e demais componentes utilizados neste protótipo, apresentados na figura, seguem o proposto pelos autores Bezerra da Cunha e da Rocha (2016) e Taneja e Bathia (2017), sendo estes: um sensor capacitivo de umidade do solo, modelo CS12; um sensor de temperatura e umidade, modelo DHT22; um módulo RTC, modelo DS3231; um módulo shield relé 5v; uma mini bomba d’água submersível e um display LCD I2C, 16x2.

![circuito](https://github.com/user-attachments/assets/7bef8c62-04f0-43dd-8ec3-d90501a453b0)

O código, conforme a figura, utiliza um limiar de umidade, que ativa a bomba d’água caso os sensores do sistema identifiquem um valor de umidade do solo menor que 40%. Nesse cenário, a bomba d'água é acionada e ficará ligada por 1 minuto para realizar a ação de irrigação e depois é desligada.
Após o processo de irrigação ou verificação da umidade, o sistema entra em um intervalo de 1 minuto antes de realizar uma nova aferição.

