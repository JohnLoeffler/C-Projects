#ifndef MULTIPLIER_HPP
#define MULTIPLIER_HPP

#include "Operation.hpp"

template<typename T>
class Multiplier : public Operator<T>{
  T a;
public:
  Multiplier(T b):Operator<T>(){this->a = b;}

  void Operate(T b){
    this->a += b;
  }
  T ReturnResult(){return a;}
};
#endif // MULTIPLIER_HPP
