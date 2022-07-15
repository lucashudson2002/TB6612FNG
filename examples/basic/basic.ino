#include <TB6612FNG.h>

#define STBY 2
#define PWMA 3
#define IN1A 4
#define IN2A 5
#define PWMB 6
#define IN1B 7
#define IN2B 8

//Create the object for TB6612FNG with the define above
TB6612FNG robot (IN1A, IN2A, IN1B, IN2B, PWMA, PWMB, STBY);
//TB6612FNG robot (IN1A, IN2A, IN1B, IN2B, PWMA, PWMB);
//TB6612FNG robot (IN1A, IN2A, IN1B, IN2B, STBY);
//TB6612FNG robot (IN1A, IN2A, IN1B, IN2B);

void setup() {
  //initialize the H-bridge and pinMode them
  robot.begin();
  //set PWM to the maximum possible
  robot.set_pwm(255);
}

void loop() {
  robot.forward(); //robot goes forward
  delay(1000);
  robot.stop(); ; //robot stops
  delay(1000);
  robot.backward(); //robot goes backward
  delay(1000);
  robot.brake(); ; //robot brakes
  delay(1000);
}
