#ifndef OPERATION_HPP
#define OPERATION_HPP
#include <string>


/**
* An abstract class interface used to perform a variety of operations on a data
* structure utilizing the Strategy Design Pattern
*/

enum Operation{
  ADD, MULTIPLY, PRINT
};

class Operator{
protected:
  int i;
  float f;
  std::string s;

  Operator(int a, float b): i(a), f(b), s(""){}
public:
  virtual void Operate(int i) = 0;
  virtual void Operate(float f) = 0;
  virtual void Operate(std::string s) = 0;
  virtual int ReturnResults_int() = 0;
  virtual float ReturnResults_float() = 0;
  virtual std::string ReturnResults_string() = 0;
  virtual ~Operator(){}
};

class Adder : public Operator{
public:
  Adder();
  virtual void Operate(int i);
  virtual void Operate(float f);
  virtual void Operate(std::string s);
  virtual int ReturnResults_int();
  virtual float ReturnResults_float();
  virtual std::string ReturnResults_string();
};

class Multiplier : public Operator{
public:
  Multiplier();
  virtual void Operate(int i);
  virtual void Operate(float f);
  virtual void Operate(std::string s);
  virtual int ReturnResults_int();
  virtual float ReturnResults_float();
  virtual std::string ReturnResults_string();
};

class Printer : public Operator{
public:
  Printer();
  virtual void Operate(int i);
  virtual void Operate(float f);
  virtual void Operate(std::string s);
  virtual int ReturnResults_int();
  virtual float ReturnResults_float();
  virtual std::string ReturnResults_string();
};


#endif // OPERATION_HPP
