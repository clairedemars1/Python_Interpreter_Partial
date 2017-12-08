#pragma once

#include <iostream>
#include "node.h"
#include "poolOfNodes.h"
using std::endl;
using std::cout;

class Literal : public Node {
public:
	Literal(): Node(), isReturnVal_variable(false) {}
	Literal(bool _isReturnVal): Node(), isReturnVal_variable(_isReturnVal) {}
	virtual ~Literal(){}

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
  
	virtual const Literal* operator<=(const Literal& rhs) const=0;
	virtual const Literal* opLessEqual(float) const=0;
	virtual const Literal* opLessEqual(int) const=0;

	virtual const Literal* operator>(const Literal& rhs) const=0;
	virtual const Literal* opGreater(float) const=0;
	virtual const Literal* opGreater(int) const=0;

	virtual const Literal* operator>=(const Literal& rhs) const=0;
	virtual const Literal* opGreaterEqual(float) const=0;
	virtual const Literal* opGreaterEqual(int) const=0;

	virtual const Literal* operator==(const Literal& rhs) const=0;
	virtual const Literal* opEqualEqual(float) const=0;
	virtual const Literal* opEqualEqual(int) const=0;

	virtual const Literal* operator!=(const Literal& rhs) const=0;
	virtual const Literal* opNotEqual(float) const=0;
	virtual const Literal* opNotEqual(int) const=0;

	virtual const Literal* eval() const=0;
	bool isReturnVal() const { return isReturnVal_variable; }
	virtual const Literal* makeReturnValCopy() const =0;
	virtual void print() const =0;
	virtual bool isTruthy() const=0;

private:
	bool isReturnVal_variable;
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

	virtual const Literal* operator<=(const Literal& rhs) const;
	virtual const Literal* opLessEqual(float) const;
	virtual const Literal* opLessEqual(int) const;

	virtual const Literal* operator>(const Literal& rhs) const;
	virtual const Literal* opGreater(float) const;
	virtual const Literal* opGreater(int) const;

	virtual const Literal* operator>=(const Literal& rhs) const;
	virtual const Literal* opGreaterEqual(float) const;
	virtual const Literal* opGreaterEqual(int) const;

	virtual const Literal* operator==(const Literal& rhs) const;
	virtual const Literal* opEqualEqual(float) const;
	virtual const Literal* opEqualEqual(int) const;

	virtual const Literal* operator!=(const Literal& rhs) const;
	virtual const Literal* opNotEqual(float) const;
	virtual const Literal* opNotEqual(int) const;

	virtual const Literal* eval() const;
	const Literal* makeReturnValCopy() const;
	bool isTruthy() const {return false; };
	virtual void print() const;
	virtual void display() const;
	
private:
    UndefLiteral(): Literal(true) {} 
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

	virtual const Literal* operator<=(const Literal& rhs) const;
	virtual const Literal* opLessEqual(float) const;
	virtual const Literal* opLessEqual(int) const;

	virtual const Literal* operator>(const Literal& rhs) const;
	virtual const Literal* opGreater(float) const;
	virtual const Literal* opGreater(int) const;

	virtual const Literal* operator>=(const Literal& rhs) const;
	virtual const Literal* opGreaterEqual(float) const;
	virtual const Literal* opGreaterEqual(int) const;

	virtual const Literal* operator==(const Literal& rhs) const;
	virtual const Literal* opEqualEqual(float) const;
	virtual const Literal* opEqualEqual(int) const;

	virtual const Literal* operator!=(const Literal& rhs) const;
	virtual const Literal* opNotEqual(float) const;
	virtual const Literal* opNotEqual(int) const;

	virtual const Literal* eval() const;
	const Literal* makeReturnValCopy() const;
	virtual void print() const;
	virtual void display() const;
	virtual bool isTruthy() const {return false; };

private:
    NoneLiteral(): Literal(true) {} 
    // for the purposes of this project, this can be always a "return node"
};

class FloatLiteral: public Literal {
public:
	FloatLiteral(float _val): val(_val) {}
	FloatLiteral(float _val, bool _isReturnVal): Literal(_isReturnVal), val(_val) {}

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

	virtual const Literal* operator<=(const Literal& rhs) const;
	virtual const Literal* opLessEqual(float) const;
	virtual const Literal* opLessEqual(int) const;

	virtual const Literal* operator>(const Literal& rhs) const;
	virtual const Literal* opGreater(float) const;
	virtual const Literal* opGreater(int) const;

	virtual const Literal* operator>=(const Literal& rhs) const;
	virtual const Literal* opGreaterEqual(float) const;
	virtual const Literal* opGreaterEqual(int) const;

	virtual const Literal* operator==(const Literal& rhs) const;
	virtual const Literal* opEqualEqual(float) const;
	virtual const Literal* opEqualEqual(int) const;

	virtual const Literal* operator!=(const Literal& rhs) const;
	virtual const Literal* opNotEqual(float) const;
	virtual const Literal* opNotEqual(int) const;

	virtual const Literal* eval() const;
	const Literal* makeReturnValCopy() const;
	virtual void print() const;
	virtual void display() const;
	virtual bool isTruthy() const {return val; };

private:
  float val;
};

class IntLiteral: public Literal {
public:
	IntLiteral(int _val): val(_val) {}
	IntLiteral(float _val, bool _isReturnVal): Literal(_isReturnVal), val(_val) {}
	~IntLiteral() {}
	
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

	virtual const Literal* operator<=(const Literal& rhs) const;
	virtual const Literal* opLessEqual(float) const;
	virtual const Literal* opLessEqual(int) const;

	virtual const Literal* operator>(const Literal& rhs) const;
	virtual const Literal* opGreater(float) const;
	virtual const Literal* opGreater(int) const;

	virtual const Literal* operator>=(const Literal& rhs) const;
	virtual const Literal* opGreaterEqual(float) const;
	virtual const Literal* opGreaterEqual(int) const;

	virtual const Literal* operator==(const Literal& rhs) const;
	virtual const Literal* opEqualEqual(float) const;
	virtual const Literal* opEqualEqual(int) const;

	virtual const Literal* operator!=(const Literal& rhs) const;
	virtual const Literal* opNotEqual(float) const;
	virtual const Literal* opNotEqual(int) const;

	virtual const Literal* eval() const;
	const Literal* makeReturnValCopy() const;
	virtual void print() const;
	virtual void display() const;
	virtual bool isTruthy() const {return val; };

protected:
	int val;
};


class BoolLiteral : public IntLiteral {
public:
	BoolLiteral(int v): IntLiteral(v) {}
	virtual void print() const {
		if ( val ){
			cout << "True" << endl;
		} else {
			cout << "False" << endl;
		}
	}
	virtual const Literal* eval() const { return this; }
};
