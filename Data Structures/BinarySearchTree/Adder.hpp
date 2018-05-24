#ifndef ADDER_HPP
#define ADDER_HPP
#include "Operation.hpp"

template <typename T>
class Adder : public Operator<T>{
  T a;
public:
  Adder(T b = 0):Operator<T>(){this->a = b;}

  void Operate(T b){
    std::cout << "'a' = " << a << " & b = " << b << std::endl;
    a += b;
  }
  T ReturnResult() {return this->a;}
};
#endif // ADDER_HPP
