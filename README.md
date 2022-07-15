# TB6612FNG
Arduino library to control the TB6612FNG Dual H-Bridge motor driver.

![TB6612FNG](/tb6612fng.jpg)

## Pinout
- VCC é a alimentação lógica (2.7V a 5.5V).
- VM é a almentação dos motores (4,5V a 13,5V).
- PWMA e PWMB é o controle dos PWMs, pinos digitais ~.
- AI1, AI2, BI1, BI2 pinos digitais para o controle do giro dos motores.
- STBY pino digital para ativar/desativar a ponte-H.
- AO1, AO2, BO1, BO2 é onde são conectados os motores.
- GND é o terra (-).

## How to use
- You need to control ate least 2 motors (one in each exit, or more) to use this library.
- The use of PWMs and the STBY pin is optional.
- To not use the pins above, just do not initialize them when creating the object.
- Any problem or suggestion, get in touch.
