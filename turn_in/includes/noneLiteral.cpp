#include "literal.h"
#include <iostream>
using std::endl;
using std::cout;


const Literal*  NoneLiteral::operator+(const Literal& ) const { return this; }
const Literal*  NoneLiteral::opPlus(float) const{ return this; }
const Literal*  NoneLiteral::opPlus(int) const{ return this; }

const Literal*  NoneLiteral::operator*(const Literal& ) const{ return this; }
const Literal*  NoneLiteral::opMult(float) const{ return this; }
const Literal*  NoneLiteral::opMult(int) const{ return this; }

const Literal*  NoneLiteral::operator-(const Literal& ) const{ return this; }
const Literal*  NoneLiteral::opSubt(float) const{ return this; }
const Literal*  NoneLiteral::opSubt(int) const{ return this; }

const Literal*  NoneLiteral::operator/(const Literal& ) const{ return this; }
const Literal*  NoneLiteral::opDiv(float) const{ return this; }
const Literal*  NoneLiteral::opDiv(int) const{ return this; }

const Literal*  NoneLiteral::operatorDoubleSlash(const Literal& ) const{ return this; }
const Literal*  NoneLiteral::opDoubleSlash(float) const{ return this; }
const Literal*  NoneLiteral::opDoubleSlash(int) const{ return this; }

const Literal*  NoneLiteral::operator%(const Literal& ) const{ return this; }
const Literal*  NoneLiteral::opMod(float) const{ return this; }
const Literal*  NoneLiteral::opMod(int) const{ return this; }

const Literal*  NoneLiteral::operatorPower(const Literal&) const{ return this; }
const Literal*  NoneLiteral::opPow(float) const{ return this; }
const Literal*  NoneLiteral::opPow(int) const{ return this; }

const Literal* NoneLiteral::operator<(const Literal&) const{ return this; }
const Literal* NoneLiteral::opLess(float) const{ return this; }
const Literal* NoneLiteral::opLess(int) const{ return this; }

const Literal* NoneLiteral::operator<=(const Literal&) const{ return this; }
const Literal* NoneLiteral::opLessEqual(float) const{ return this; }
const Literal* NoneLiteral::opLessEqual(int) const{ return this; }

const Literal* NoneLiteral::operator>(const Literal&) const{ return this; }
const Literal* NoneLiteral::opGreater(float) const{ return this; }
const Literal* NoneLiteral::opGreater(int) const{ return this; }

const Literal* NoneLiteral::operator>=(const Literal&) const{ return this; }
const Literal* NoneLiteral::opGreaterEqual(float) const{ return this; }
const Literal* NoneLiteral::opGreaterEqual(int) const{ return this; }

const Literal* NoneLiteral::operator==(const Literal&) const{ return this; }
const Literal* NoneLiteral::opEqualEqual(float) const{ return this; }
const Literal* NoneLiteral::opEqualEqual(int) const{ return this; }

const Literal* NoneLiteral::operator!=(const Literal&) const{ return this; }
const Literal* NoneLiteral::opNotEqual(float) const{ return this; }
const Literal* NoneLiteral::opNotEqual(int) const{ return this; }

const Literal*  NoneLiteral::eval() const{ return this; }
void NoneLiteral::print() const{ cout << "None" << endl; }
void NoneLiteral::display() const{ cout << "None" << endl; }
