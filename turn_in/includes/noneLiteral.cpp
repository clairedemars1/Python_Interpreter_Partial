#include "literal.h"
#include <iostream>
using std::endl;
using std::cout;


Literal* NoneLiteral::operator+(const Literal& rhs) const { return this; }
Literal* NoneLiteral::opPlus(float) const{ return this; }
Literal* NoneLiteral::opPlus(int) const{ return this; }

Literal* NoneLiteral::operator*(const Literal& rhs) const{ return this; }
Literal* NoneLiteral::opMult(float) const{ return this; }
Literal* NoneLiteral::opMult(int) const{ return this; }

Literal* NoneLiteral::operator-(const Literal& rhs) const{ return this; }
Literal* NoneLiteral::opSubt(float) const{ return this; }
Literal* NoneLiteral::opSubt(int) const{ return this; }

Literal* NoneLiteral::operator/(const Literal& rhs) const{ return this; }
Literal* NoneLiteral::opDiv(float) const{ return this; }
Literal* NoneLiteral::opDiv(int) const{ return this; }

Literal* NoneLiteral::operatorDoubleSlash(const Literal& rhs) const{ return this; }
Literal* NoneLiteral::opDoubleSlash(float) const{ return this; }
Literal* NoneLiteral::opDoubleSlash(int) const{ return this; }

Literal* NoneLiteral::operator%(const Literal& rhs) const{ return this; }
Literal* NoneLiteral::opMod(float) const{ return this; }
Literal* NoneLiteral::opMod(int) const{ return this; }

Literal* NoneLiteral::operatorPower(const Literal& rhs) const{ return this; }
Literal* NoneLiteral::opPow(float) const{ return this; }
Literal* NoneLiteral::opPow(int) const{ return this; }

const Literal* NoneLiteral::eval() const{ return this; }
void NoneLiteral::print() const{ cout << "None" << endl; }
void NoneLiteral::changeSign(){ }
void NoneLiteral::display() const{ cout << "None" << endl; }
