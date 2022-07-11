#ifndef TB6612FNG_H
#define TB6612FNG_H

#include <Arduino.h>

class TB6612FNG{
private:
  byte in1_left, in2_left, in1_right, in2_right;
  int pwm_left, pwm_right, stby;
  int valor;
  throw_pwm(byte PWM_left, byte PWM_right);
public:
  TB6612FNG(byte IN1_left, byte IN2_left, byte IN1_right, byte IN2_right, int PWM_left, int PWM_right , int STBY=-1):
    in1_left(IN1_left), in2_left(IN2_left), in1_right(IN1_right), in2_right(IN2_right), pwm_left(PWM_left), pwm_right(PWM_right), stby(STBY){}
  TB6612FNG(byte IN1_left, byte IN2_left, byte IN1_right, byte IN2_right, int STBY=-1):
    TB6612FNG(IN1_left, IN2_left, IN1_right, IN2_right, -1, -1, STBY){}
  begin();
  set_pwm(int valor);
  parar();
  frear();
  frente();
  tras();
  direita();
  esquerda();
  frente_direita();
  frente_esquerda();
  tras_direita();
  tras_esquerda();  
};

#endif
