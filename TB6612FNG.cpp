#include "TB6612FNG.h"

TB6612FNG::begin(){
  pinMode(in1_left, OUTPUT);
  pinMode(in2_left, OUTPUT);
  pinMode(in1_right, OUTPUT);
  pinMode(in2_right, OUTPUT);
  if (stby!=-1) pinMode(stby, OUTPUT);
  pwm_left!=-1 && pwm_right!=-1 ? value = 0 : value = -1;
  if (value!=-1){
    pinMode(pwm_left, OUTPUT);
    pinMode(pwm_right, OUTPUT);
  }
  stop();
}

TB6612FNG::set_pwm(int value){
  if (this->value!=-1) this->value = value;
  if (throw_) throw_pwm(value, value);
}

TB6612FNG::throw_pwm(byte PWM_left, byte PWM_right){
  if (stby!=-1) digitalWrite(stby, HIGH);
  if (value!=-1){
    analogWrite(pwm_left, PWM_left);
    analogWrite(pwm_right, PWM_right);
  }
}

TB6612FNG::stop(){
  throw_pwm(0, 0);
  throw_ = false;
  if (stby!=-1) digitalWrite(stby, LOW);
  digitalWrite(in1_right, LOW);
  digitalWrite(in2_right, LOW);
  digitalWrite(in1_left, LOW);
  digitalWrite(in2_left, LOW);
}
TB6612FNG::brake(){
  throw_pwm(255, 255);
  throw_ = false;
  digitalWrite(in1_right, HIGH);
  digitalWrite(in2_right, HIGH);
  digitalWrite(in1_left, HIGH);
  digitalWrite(in2_left, HIGH);
}
TB6612FNG::forward(){
  throw_ = true;
  throw_pwm(value, value);
  digitalWrite(in1_right, HIGH);
  digitalWrite(in2_right, LOW);
  digitalWrite(in1_left, HIGH);
  digitalWrite(in2_left, LOW);
}
TB6612FNG::backward(){
  throw_ = true;
  throw_pwm(value, value);
  digitalWrite(in1_right, LOW);
  digitalWrite(in2_right, HIGH);
  digitalWrite(in1_left, LOW);
  digitalWrite(in2_left, HIGH);
}
TB6612FNG::right(){
  throw_ = true;
  throw_pwm(value, 0);
  digitalWrite(in1_right, LOW);
  digitalWrite(in2_right, LOW);
  digitalWrite(in1_left, HIGH);
  digitalWrite(in2_left, LOW);
}
TB6612FNG::left(){
  throw_ = true;
  throw_pwm(0, value);
  digitalWrite(in1_right, HIGH);
  digitalWrite(in2_right, LOW);
  digitalWrite(in1_left, LOW);
  digitalWrite(in2_left, LOW);
}
TB6612FNG::forward_right(){
  forward();
  throw_pwm(value, 0.5*value);
}
TB6612FNG::forward_left(){
  forward();
  throw_pwm(0.5*value, value);
}
TB6612FNG::backward_right(){
  backward();
  throw_pwm(value, 0.5*value);
}
TB6612FNG::backward_left(){
  backward();
  throw_pwm(0.5*value, value);
} 
