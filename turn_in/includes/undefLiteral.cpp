#include "literal.h"
#include <iostream>
using std::endl;
using std::cout;


Literal* UndefLiteral::operator+(const Literal& rhs) const{ return *this; }
Literal* UndefLiteral::opPlus(float) const{ return *this; }
Literal* UndefLiteral::opPlus(int) const{ return *this; }

Literal* UndefLiteral::operator*(const Literal& rhs) const{ return *this; }
Literal* UndefLiteral::opMult(float) const{ return *this; }
Literal* UndefLiteral::opMult(int) const{ return *this; }

Literal* UndefLiteral::operator-(const Literal& rhs) const{ return *this; }
Literal* UndefLiteral::opSubt(float) const{ return *this; }
Literal* UndefLiteral::opSubt(int) const{ return *this; }

Literal* UndefLiteral::operator/(const Literal& rhs) const{ return *this; }
Literal* UndefLiteral::opDiv(float) const{ return *this; }
Literal* UndefLiteral::opDiv(int) const{ return *this; }

Literal* UndefLiteral::operatorDoubleSlash(const Literal& rhs) const{ return *this; }
Literal* UndefLiteral::opDoubleSlash(float) const{ return *this; }
Literal* UndefLiteral::opDoubleSlash(int) const{ return *this; }

Literal* UndefLiteral::operator%(const Literal& rhs) const{ return *this; }
Literal* UndefLiteral::opMod(float) const{ return *this; }
Literal* UndefLiteral::opMod(int) const{ return *this; }

Literal* UndefLiteral::operatorPower(const Literal& rhs) const{ return *this; }
Literal* UndefLiteral::opPow(float) const{ return *this; }
Literal* UndefLiteral::opPow(int) const{ return *this; }

const Literal* UndefLiteral::eval() const{ return *this; }
void UndefLiteral::print() const{ cout << "Undef" << endl; }
void UndefLiteral::changeSign(){ }
void UndefLiteral::display() const{ cout << "Undef" << endl; }
