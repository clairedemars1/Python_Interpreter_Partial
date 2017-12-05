#pragma once

#include <iostream>
#include "node.h"
#include "poolOfNodes.h"
using std::endl;
using std::cout;

class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual const Literal* operator+(const Literal& rhs) const =0;
  virtual const Literal* opPlus(float) const =0;
  virtual const Literal* opPlus(int) const =0;

  virtual const Literal* operator*(const Literal& rhs) const =0;
  virtual const Literal* opMult(float) const =0;
  virtual const Literal* opMult(int) const =0;

  virtual const Literal* operator-(const Literal& rhs) const =0;
  virtual const Literal* opSubt(float) const =0;
  virtual const Literal* opSubt(int) const =0;

  virtual const Literal* operator/(const Literal& rhs) const =0;
  virtual const Literal* opDiv(float) const =0;
  virtual const Literal* opDiv(int) const =0;

  virtual const Literal* operatorDoubleSlash(const Literal& rhs) const=0;
  virtual const Literal* opDoubleSlash(float) const=0;
  virtual const Literal* opDoubleSlash(int) const=0;
  
  virtual const Literal* operator%(const Literal& rhs) const=0;
  virtual const Literal* opMod(float) const=0;
  virtual const Literal* opMod(int) const=0;
  
  virtual const Literal* operatorPower(const Literal& rhs) const=0;
  virtual const Literal* opPow(float) const=0;
  virtual const Literal* opPow(int) const=0;

  virtual const Literal* operator<(const Literal& rhs) const=0;
  virtual const Literal* opLess(float) const=0;
  virtual const Literal* opLess(int) const=0;

  virtual const Literal* eval() const =0;
  virtual void print() const =0;
};

// an undefined Node
class UndefLiteral: public Literal {
public: 
  static const Literal& getInstance() { 
	  static const UndefLiteral instance;
	  return instance; 
  }
  virtual const Literal* operator+(const Literal& rhs) const;
  virtual const Literal* opPlus(float) const;
  virtual const Literal* opPlus(int) const;

  virtual const Literal* operator*(const Literal& rhs) const;
  virtual const Literal* opMult(float) const;
  virtual const Literal* opMult(int) const;

  virtual const Literal* operator-(const Literal& rhs) const;
  virtual const Literal* opSubt(float) const;
  virtual const Literal* opSubt(int) const;

  virtual const Literal* operator/(const Literal& rhs) const;
  virtual const Literal* opDiv(float) const;
  virtual const Literal* opDiv(int) const;
  
  virtual const Literal* operatorDoubleSlash(const Literal& rhs) const;
  virtual const Literal* opDoubleSlash(float) const;
  virtual const Literal* opDoubleSlash(int) const;
  
  virtual const Literal* operator%(const Literal& rhs) const;
  virtual const Literal* opMod(float) const;
  virtual const Literal* opMod(int) const;
  
  virtual const Literal* operatorPower(const Literal& rhs) const;
  virtual const Literal* opPow(float) const;
  virtual const Literal* opPow(int) const;
  
  virtual const Literal* operator<(const Literal& rhs) const;
  virtual const Literal* opLess(float) const;
  virtual const Literal* opLess(int) const;

  virtual const Literal* eval() const;
  virtual void print() const;
  virtual void display() const;
private:
    UndefLiteral() {}
};

class NoneLiteral: public Literal {
public: 
  static const Literal& getInstance() { 
	  static const NoneLiteral instance;
	  return instance; 
  }
  virtual const Literal* operator+(const Literal& rhs) const;
  virtual const Literal* opPlus(float) const;
  virtual const Literal* opPlus(int) const;

  virtual const Literal* operator*(const Literal& rhs) const;
  virtual const Literal* opMult(float) const;
  virtual const Literal* opMult(int) const;

  virtual const Literal* operator-(const Literal& rhs) const;
  virtual const Literal* opSubt(float) const;
  virtual const Literal* opSubt(int) const;

  virtual const Literal* operator/(const Literal& rhs) const;
  virtual const Literal* opDiv(float) const;
  virtual const Literal* opDiv(int) const;
  
  virtual const Literal* operatorDoubleSlash(const Literal& rhs) const;
  virtual const Literal* opDoubleSlash(float) const;
  virtual const Literal* opDoubleSlash(int) const;
  
  virtual const Literal* operator%(const Literal& rhs) const;
  virtual const Literal* opMod(float) const;
  virtual const Literal* opMod(int) const;
  
  virtual const Literal* operatorPower(const Literal& rhs) const;
  virtual const Literal* opPow(float) const;
    virtual const Literal* opPow(int) const;
  
  virtual const Literal* operator<(const Literal& rhs) const;
  virtual const Literal* opLess(float) const;
  virtual const Literal* opLess(int) const;

  virtual const Literal* eval() const;
  virtual void print() const;
  virtual void display() const;

private:
    NoneLiteral() {}
};

class FloatLiteral: public Literal {
public:
  FloatLiteral(float _val): val(_val) {}
  virtual const Literal* operator+(const Literal& rhs) const;
  virtual const Literal* opPlus(float) const;
  virtual const Literal* opPlus(int) const;

  virtual const Literal* operator*(const Literal& rhs) const;
  virtual const Literal* opMult(float) const;
  virtual const Literal* opMult(int) const;

  virtual const Literal* operator-(const Literal& rhs) const;
  virtual const Literal* opSubt(float) const;
  virtual const Literal* opSubt(int) const;

  virtual const Literal* operator/(const Literal& rhs) const;
  virtual const Literal* opDiv(float) const;
  virtual const Literal* opDiv(int) const;
  
  virtual const Literal* operatorDoubleSlash(const Literal& rhs) const;
  virtual const Literal* opDoubleSlash(float) const;
  virtual const Literal* opDoubleSlash(int) const;
  
  virtual const Literal* operator%(const Literal& rhs) const;
  virtual const Literal* opMod(float) const;
  virtual const Literal* opMod(int) const;
  
  virtual const Literal* operatorPower(const Literal& rhs) const;
  virtual const Literal* opPow(float) const;
    virtual const Literal* opPow(int) const;
  
  virtual const Literal* operator<(const Literal& rhs) const;
  virtual const Literal* opLess(float) const;
  virtual const Literal* opLess(int) const;

  virtual const Literal* eval() const;
  virtual void print() const;
  virtual void display() const;
private:
  float val;
};

class IntLiteral: public Literal {
public:
  IntLiteral(int _val): val(_val) {}
  virtual const Literal* operator+(const Literal& rhs) const;
  virtual const Literal* opPlus(float) const;
  virtual const Literal* opPlus(int) const;

  virtual const Literal* operator*(const Literal& rhs) const;
  virtual const Literal* opMult(float) const;
  virtual const Literal* opMult(int) const;

  virtual const Literal* operator-(const Literal& rhs) const;
  virtual const Literal* opSubt(float) const;
  virtual const Literal* opSubt(int) const;

  virtual const Literal* operator/(const Literal& rhs) const;
  virtual const Literal* opDiv(float) const;
  virtual const Literal* opDiv(int) const;
  
  virtual const Literal* operatorDoubleSlash(const Literal& rhs) const;
  virtual const Literal* opDoubleSlash(float) const;
  virtual const Literal* opDoubleSlash(int) const;
  
  virtual const Literal* operator%(const Literal& rhs) const;
  virtual const Literal* opMod(float) const;
  virtual const Literal* opMod(int) const;
  
  virtual const Literal* operatorPower(const Literal& rhs) const;
  virtual const Literal* opPow(float) const;
  virtual const Literal* opPow(int) const;
  
  virtual const Literal* operator<(const Literal& rhs) const;
  virtual const Literal* opLess(float) const;
  virtual const Literal* opLess(int) const;
  
  virtual const Literal* eval() const;
  virtual void print() const;
  virtual void display() const;


private:
  int val;
};


class BoolLiteral : public IntLiteral {
public:
	BoolLiteral(int v): IntLiteral(v), bool_val(v){}
	virtual void print() const {
		if ( bool_val ){
			cout << "True" << endl;
		} else {
			cout << "False" << endl;
		}
	}
	virtual const Literal* eval() const {
		return this;
	}
private:
	bool bool_val;
};
