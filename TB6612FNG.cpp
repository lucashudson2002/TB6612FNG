#include "TB6612FNG.h"

TB6612FNG::begin(){
  pinMode(in1_left, OUTPUT);
  pinMode(in2_left, OUTPUT);
  pinMode(in1_right, OUTPUT);
  pinMode(in2_right, OUTPUT);
  if (stby!=-1) pinMode(stby, OUTPUT);
  pwm_left!=-1 && pwm_right!=-1 ? valor = 0 : valor = -1;
  if (valor!=-1){
    pinMode(pwm_left, OUTPUT);
    pinMode(pwm_right, OUTPUT);
  }
  parar();
}

TB6612FNG::set_pwm(int valor){
  if (this->valor!=-1) this->valor = valor;
}

TB6612FNG::throw_pwm(byte PWM_left, byte PWM_right){
  if (stby!=-1) digitalWrite(stby, HIGH);
  if (valor!=-1){
    analogWrite(pwm_left, PWM_left);
    analogWrite(pwm_right, PWM_right);
  }
}

TB6612FNG::parar(){
  throw_pwm(0, 0);
  if (stby!=-1) digitalWrite(stby, LOW);
  digitalWrite(in1_right, LOW);
  digitalWrite(in2_right, LOW);
  digitalWrite(in1_left, LOW);
  digitalWrite(in2_left, LOW);
}
TB6612FNG::frear(){
  throw_pwm(255, 255);
  digitalWrite(in1_right, HIGH);
  digitalWrite(in2_right, HIGH);
  digitalWrite(in1_left, HIGH);
  digitalWrite(in2_left, HIGH);
}
TB6612FNG::frente(){
  throw_pwm(valor, valor);
  digitalWrite(in1_right, HIGH);
  digitalWrite(in2_right, LOW);
  digitalWrite(in1_left, HIGH);
  digitalWrite(in2_left, LOW);
}
TB6612FNG::tras(){
  throw_pwm(valor, valor);
  digitalWrite(in1_right, LOW);
  digitalWrite(in2_right, HIGH);
  digitalWrite(in1_left, LOW);
  digitalWrite(in2_left, HIGH);
}
TB6612FNG::direita(){
  throw_pwm(valor, 0);
  digitalWrite(in1_right, LOW);
  digitalWrite(in2_right, LOW);
  digitalWrite(in1_left, HIGH);
  digitalWrite(in2_left, LOW);
}
TB6612FNG::esquerda(){
  throw_pwm(0, valor);
  digitalWrite(in1_right, HIGH);
  digitalWrite(in2_right, LOW);
  digitalWrite(in1_left, LOW);
  digitalWrite(in2_left, LOW);
}
TB6612FNG::frente_direita(){
  frente();
  throw_pwm(valor, 0.5*valor);
}
TB6612FNG::frente_esquerda(){
  frente();
  throw_pwm(0.5*valor, valor);
}
TB6612FNG::tras_direita(){
  tras();
  throw_pwm(valor, 0.5*valor);
}
TB6612FNG::tras_esquerda(){
  tras();
  throw_pwm(0.5*valor, valor);
} 
