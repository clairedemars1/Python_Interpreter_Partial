#include "literal.h"
#include <iostream>
using std::endl;
using std::cout;


const Literal*  UndefLiteral::operator+(const Literal&) const{ return this; }
const Literal*  UndefLiteral::opPlus(float) const{ return this; }
const Literal*  UndefLiteral::opPlus(int) const{ return this; }

const Literal*  UndefLiteral::operator*(const Literal&) const{ return this; }
const Literal*  UndefLiteral::opMult(float) const{ return this; }
const Literal*  UndefLiteral::opMult(int) const{ return this; }

const Literal*  UndefLiteral::operator-(const Literal&) const{ return this; }
const Literal*  UndefLiteral::opSubt(float) const{ return this; }
const Literal*  UndefLiteral::opSubt(int) const{ return this; }

const Literal*  UndefLiteral::operator/(const Literal&) const{ return this; }
const Literal*  UndefLiteral::opDiv(float) const{ return this; }
const Literal*  UndefLiteral::opDiv(int) const{ return this; }

const Literal*  UndefLiteral::operatorDoubleSlash(const Literal&) const{ return this; }
const Literal*  UndefLiteral::opDoubleSlash(float) const{ return this; }
const Literal*  UndefLiteral::opDoubleSlash(int) const{ return this; }

const Literal*  UndefLiteral::operator%(const Literal&) const{ return this; }
const Literal*  UndefLiteral::opMod(float) const{ return this; }
const Literal*  UndefLiteral::opMod(int) const{ return this; }

const Literal*  UndefLiteral::operatorPower(const Literal&) const{ return this; }
const Literal*  UndefLiteral::opPow(float) const{ return this; }
const Literal*  UndefLiteral::opPow(int) const{ return this; }

const Literal*  UndefLiteral::eval() const{ return this; }
void UndefLiteral::print() const{ cout << "Undef" << endl; }
void UndefLiteral::display() const{ cout << "Undef" << endl; }
