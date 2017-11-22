#pragma once

#include <iostream>
#include "node.h"
#include "poolOfNodes.h"
using std::endl;
using std::cout;

class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual Literal* operator+(const Literal& rhs) const =0;
  virtual Literal* opPlus(float) const =0;
  virtual Literal* opPlus(int) const =0;

  virtual Literal* operator*(const Literal& rhs) const =0;
  virtual Literal* opMult(float) const =0;
  virtual Literal* opMult(int) const =0;

  virtual Literal* operator-(const Literal& rhs) const =0;
  virtual Literal* opSubt(float) const =0;
  virtual Literal* opSubt(int) const =0;

  virtual Literal* operator/(const Literal& rhs) const =0;
  virtual Literal* opDiv(float) const =0;
  virtual Literal* opDiv(int) const =0;

  virtual Literal* operatorDoubleSlash(const Literal& rhs) const=0;
  virtual Literal* opDoubleSlash(float) const=0;
  virtual Literal* opDoubleSlash(int) const=0;
  
  virtual Literal* operator%(const Literal& rhs) const=0;
  virtual Literal* opMod(float) const=0;
  virtual Literal* opMod(int) const=0;
  
  virtual Literal* operatorPower(const Literal& rhs) const=0;
  virtual Literal* opPow(float) const=0;
  virtual Literal* opPow(int) const=0;

  virtual const Literal* eval() const =0;
  virtual void print() const =0; // this used to define default behavior, but that wouldn't compile (maybe b/c all these headers are in the same file)
  virtual void changeSign() {}
};

class FloatLiteral: public Literal {
public:
  FloatLiteral(float _val): val(_val) {}
  virtual Literal* operator+(const Literal& rhs) const;
  virtual Literal* opPlus(float) const;
  virtual Literal* opPlus(int) const;

  virtual Literal* operator*(const Literal& rhs) const;
  virtual Literal* opMult(float) const;
  virtual Literal* opMult(int) const;

  virtual Literal* operator-(const Literal& rhs) const;
  virtual Literal* opSubt(float) const;
  virtual Literal* opSubt(int) const;

  virtual Literal* operator/(const Literal& rhs) const;
  virtual Literal* opDiv(float) const;
  virtual Literal* opDiv(int) const;
  
  virtual Literal* operatorDoubleSlash(const Literal& rhs) const;
  virtual Literal* opDoubleSlash(float) const;
  virtual Literal* opDoubleSlash(int) const;
  
  virtual Literal* operator%(const Literal& rhs) const;
  virtual Literal* opMod(float) const;
  virtual Literal* opMod(int) const;
  
  virtual Literal* operatorPower(const Literal& rhs) const;
  virtual Literal* opPow(float) const;
  virtual Literal* opPow(int) const;

  virtual const Literal* eval() const;
  virtual void print() const;
  void changeSign() { 
	  val *= -1;
	  //~ cout << "make neg" << endl;
  }
private:
  float val;
};

class IntLiteral: public Literal {
public:
  IntLiteral(int _val): val(_val) {}
  virtual Literal* operator+(const Literal& rhs) const;
  virtual Literal* opPlus(float) const;
  virtual Literal* opPlus(int) const;

  virtual Literal* operator*(const Literal& rhs) const;
  virtual Literal* opMult(float) const;
  virtual Literal* opMult(int) const;

  virtual Literal* operator-(const Literal& rhs) const;
  virtual Literal* opSubt(float) const;
  virtual Literal* opSubt(int) const;

  virtual Literal* operator/(const Literal& rhs) const;
  virtual Literal* opDiv(float) const;
  virtual Literal* opDiv(int) const;
  
  virtual Literal* operatorDoubleSlash(const Literal& rhs) const;
  virtual Literal* opDoubleSlash(float) const;
  virtual Literal* opDoubleSlash(int) const;
  
  virtual Literal* operator%(const Literal& rhs) const;
  virtual Literal* opMod(float) const;
  virtual Literal* opMod(int) const;
  
  virtual Literal* operatorPower(const Literal& rhs) const;
  virtual Literal* opPow(float) const;
  virtual Literal* opPow(int) const;
  
  virtual const Literal* eval() const;
  virtual void print() const;
  void changeSign() { 
	  val *= -1;
  }
private:
  int val;
};

