# PROPOSTA DE AUTOMAÇÃO DE UM SISTEMA DE IRRIGAÇÃO NO SEMIÁRIDO BRASILEIRO UTILIZANDO UMA PLACA DE PROTOTIPAGEM #
Este foi o meu Trabalho de Conclusão de Curso de Tecnologia em Gestão Ambiental, no IFCE - Campus Camocim.
Segue parte da metodologia:

- Para a idealização do sistema de irrigação, utilizou-se o Arduino UNO.
- Os sensores e demais componentes utilizados neste protótipo, apresentados na figura, seguem o proposto pelos autores Bezerra da Cunha e da Rocha (2016) e Taneja e Bathia (2017), sendo estes: um sensor capacitivo de umidade do solo, modelo CS12; um sensor de temperatura e umidade, modelo DHT22; um módulo RTC, modelo DS3231; um módulo shield relé 5v; uma mini bomba d’água submersível e um display LCD I2C, 16x2.

![circuito](https://github.com/user-attachments/assets/7bef8c62-04f0-43dd-8ec3-d90501a453b0)

- O código, conforme a figura, utiliza um limiar de umidade, que ativa a bomba d’água caso os sensores do sistema identifiquem um valor de umidade do solo menor que 40%.
- Também é definido um horário de funcionamento do sistema, entre 6h e 16h.
- Em seguida, o código entra em uma verificação por meio de uma estrutura condicional if, na qual são verificadas as condições de temperatura, umidade do ar e do solo.
- Caso o valor de umidade lido pelo sensor de umidade do solo seja menor ou igual a 40%, significa que o solo está seco.
- Nesse caso, é utilizada a estrutura de repetição while.
- Ela mantém o processo de irrigação enquanto a umidade do solo for menor ou igual a 40%.
- Após o solo atingir um nível superior a 40%, o relé e a bomba permanecem desligados. Essa verificação é feita a cada cinco segundos.
- Em seguida, aguarda-se 1 hora até a próxima leitura.

![fluxograma](https://github.com/user-attachments/assets/561092cc-5a01-45a7-b39e-4390d3d37b19)
