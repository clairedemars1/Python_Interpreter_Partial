#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "ast.h"
#include "tableManager.h"
using std::endl;
using std::cout;
using std::string;

const Literal* PrintNode::eval() const {
	const Literal* temp = printMe->eval();
	if (temp) temp->print();
	return nullptr;
}
void PrintNode::display() const { 
	cout << "PrintNode" << endl;
	if (printMe) printMe->display();
}

const Literal* FuncAsgNode::eval() const {
	cout << "func asg node  eval " << endl;
	std::string name = ident->getIdent();
	TableManager::getInstance().setFunc(name, func); 
	return nullptr;
}

void FuncAsgNode::display() const { 
	cout << "FuncAsgNode" << endl;
	ident->display();
	func->display();
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

void SuiteNode::display() const {
	for(auto s: statements){
		cout << "stmt" << endl;
		if (s) s->display();
	}
}

const Literal* IdentNode::eval() const { 
  const Literal* val = TableManager::getInstance().getVar(ident);
  return val;
}

void IdentNode::display() const { 
	cout << "IdentNode: " << getIdent() << endl;
}

const Literal* CallNode::eval() const {

	// push an scope to the tableManager, get implementation from symbol table, call it, pop that scope
	TableManager&  manager = TableManager::getInstance();
	manager.pushScope();
	string function_name = ident->getIdent();
	const FuncNode* function_impl = static_cast<const FuncNode*>( manager.getFunc(function_name) );
	
	cout <<  ident->getIdent() << endl;
	
	function_impl->eval();
	
	manager.popScope();
	
	return nullptr;
}

void CallNode::display() const {
	cout << "CallNode" << endl;
	ident->display();
}

AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) {
}

const Literal* AsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "asg binary node error";
  }
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  TableManager::getInstance().setVar(n, res);
  return res;
}

const Literal* AddBinaryNode::eval() const { 
  if (!left || !right) {
    throw "add binary node error";
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
    throw "sub binary node error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  Literal* result = (*x)-(*y);
  if ( isNegative() ){ result->changeSign(); }
  return result;
}

const Literal* MulBinaryNode::eval() const { 
  if (!left || !right) {
    throw "mul error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  Literal* result = (*x)*(*y);
  if ( isNegative() ){ result->changeSign(); }
  return result;
}

const Literal* DivBinaryNode::eval() const { 
  if (!left || !right) {
    throw "div error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  Literal* result = (*x)/(*y);
  if ( isNegative() ){ result->changeSign(); }
  return result;
}

const Literal* DoubleSlashBinaryNode::eval() const { 
  if (!left || !right) {
    throw "double slash error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  Literal* result = (*x).operatorDoubleSlash(*y);
  if ( isNegative() ){ result->changeSign(); }
  return result;
}

const Literal* ModBinaryNode::eval() const { 
  if (!left || !right) {
    throw "mod error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  Literal* result = (*x).operator %(*y);
  if ( isNegative() ){ result->changeSign(); }
  return result;
}

const Literal* PowBinaryNode::eval() const { 
  if (!left || !right) {
    throw "pow error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  Literal* result = (*x).operatorPower(*y);
  if ( isNegative() ){ result->changeSign(); }
  return result;
}

