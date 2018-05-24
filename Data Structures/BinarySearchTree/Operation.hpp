#ifndef OPERATION_HPP
#define OPERATION_HPP
/**
* An abstract class interface used to perform a variety of operations on a data
* structure utilizing the Strategy Design Pattern
*/

enum Operation{
  ADD, MULTIPLY /*, CONCAT*/ , PRINT
};

template <typename T>
class Operator{
public:
  Operator(){}
  virtual void Operate(T t){}
  virtual T ReturnResults(){}
};

#endif // OPERATION_HPP
