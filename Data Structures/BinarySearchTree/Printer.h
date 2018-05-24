#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <iostream>
#include "Operation.hpp"

template <typename T>
class Printer : public Operator<T>{
  T* t = new T();
  public:
  Printer():Operator<T>(){}

  void Operate(T output){
    std::cout << "[" << output << "[" << std::endl;
  }

  T ReturnResult(){return *t;}
};

#endif // PRINTER_HPP
