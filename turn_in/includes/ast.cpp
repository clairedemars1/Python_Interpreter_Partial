#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "symbolTable.h"
using std::endl;
using std::cout;


void FuncNode::addStatement(const Node* node){
	suite->addStatement(node);
}

const Literal* FuncNode::eval() const {
	return nullptr;
}

void SuiteNode::addStatement(const Node* node){
	statements.push_back(node);
}

const Literal* SuiteNode::eval() const {
	for(auto s: statements){
		if (s) s->eval();
	}
	return nullptr;
}

const Literal* IdentNode::eval() const { 
  SymbolTable::getInstance().display();
  const Literal* val = SymbolTable::getInstance().getVar(ident);
  return val;
}

const Literal* CallNode::eval() const {
	return nullptr;
}

AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) {
 
}


const Literal* AsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setVar(n, res);
  return res;
}

const Literal* AddBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
   Literal* result = (*x)+(*y);
  if ( isNegative() ){ result->changeSign(); }
  return result;
  //return (*x).operator+(*y);
}

const Literal* SubBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  Literal* result = (*x)-(*y);
  if ( isNegative() ){ result->changeSign(); }
  return result;
}

const Literal* MulBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  Literal* result = (*x)*(*y);
  if ( isNegative() ){ result->changeSign(); }
  return result;
}

const Literal* DivBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  Literal* result = (*x)/(*y);
  if ( isNegative() ){ result->changeSign(); }
  return result;
}

const Literal* DoubleSlashBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  Literal* result = (*x).operatorDoubleSlash(*y);
  if ( isNegative() ){ result->changeSign(); }
  return result;
}

const Literal* ModBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  Literal* result = (*x).operator %(*y);
  if ( isNegative() ){ result->changeSign(); }
  return result;
}

const Literal* PowBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  Literal* result = (*x).operatorPower(*y);
  if ( isNegative() ){ result->changeSign(); }
  return result;
}

