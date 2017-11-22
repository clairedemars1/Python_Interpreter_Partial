#pragma once
#include <iostream>

class Literal;

class Node {
public:
  Node() {}
  virtual ~Node() {}
  virtual const Literal* eval() const = 0;
  virtual void print() const { 
    std::cout << "NODE" << std::endl; 
  }
  virtual void changeSign(){ std::cout << "you should not be calling me" << std::endl; }
protected:
  virtual bool isNegative() const { return false; }
};

