#include <TB6612FNG.h>

#define STBY 2
#define PWMA 3
#define IN1A 4
#define IN2A 5
#define PWMB 6
#define IN1B 7
#define IN2B 8

TB6612FNG robot (IN1A, IN2A, IN1B, IN2B, PWMA, PWMB, STBY);

void setup() {
  robot.begin();
  robot.set_pwm(255);
}

void loop() {
  robot.forward();
  delay(1000);
  robot.stop();
  delay(1000);
  robot.backward();
  delay(1000);
  robot.stop();
  delay(1000);
}
