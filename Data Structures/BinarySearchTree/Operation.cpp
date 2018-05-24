#include "Operation.hpp"
#include <iostream>

Adder::Adder(): Operator(0, 0.f){}

void Adder::Operate(int i){
  std::cout << this->i <<" + " << i << " = ";
  this->i += i;
  std::cout << this->i << std::endl;
}
void Adder::Operate(float f){
  this->f += f;
}
void Adder::Operate(std::string s){
  this->s += s;
}
int Adder::ReturnResults_int(){
  int t = i;
  i = 0;
  return t;
}
float Adder::ReturnResults_float(){
  float t = f;
  f = 0.f;
  return t;
}
std::string Adder::ReturnResults_string(){
  std::string t = s;
  s = "";
  return t;
}

Multiplier::Multiplier(): Operator(1, 1.f){}

void Multiplier::Operate(int i=1){
  std::cout << this->i <<" x " << i << " = ";
  this->i *= i;
  std::cout << this->i << std::endl;
}
void Multiplier::Operate(float f=1.f){
  std::cout << this->f <<" x " << f << " = ";
  this->f *= f;
  std::cout << this->f << std::endl;
}
void Multiplier::Operate(std::string s = ""){
  this->s += s;
}
int Multiplier::ReturnResults_int(){
  int t = i;
  i = 1;
  return t;
}
float Multiplier::ReturnResults_float(){
  float t = f;
  f = 1.f;
  return t;
}
std::string Multiplier::ReturnResults_string(){
  return s;
}

Printer::Printer(): Operator(0, 0.f){}
void Printer::Operate(int i=0){
  std::cout << "[" << i << "]\n";
}
void Printer::Operate(float f=0.f){
  std::cout << "[" << f << "]\n";
}
void Printer::Operate(std::string s = ""){
  std::cout << "[" << s << "]\n";
}
int Printer::ReturnResults_int(){
  return i;
}
float Printer::ReturnResults_float(){
  return f;
}
std::string Printer::ReturnResults_string(){
  return "";
}
