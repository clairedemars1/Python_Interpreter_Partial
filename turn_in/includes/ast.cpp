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


const Literal* ReturnNode::eval() const {	
	if (!returnMe){ throw std::string("error with return node"); }
	return returnMe->eval();
}
void ReturnNode::display() const { 
	cout << "ReturnNode" << endl;
	if (returnMe) returnMe->display();
}

const Literal* PrintNode::eval() const {
	if (!printMe){ throw std::string("error with print node"); }
	const Literal* temp = printMe->eval();
	if (temp) temp->print();
	return nullptr;
}
void PrintNode::display() const { 
	cout << "PrintNode" << endl;
	if (printMe) printMe->display();
}

const Literal* FuncAsgNode::eval() const {
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
		// todo: make work for if statements too
		const ReturnNode* doReturn = dynamic_cast<const ReturnNode*>(s);
		if (doReturn) { return s->eval(); }
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

const Literal* FuncNode::eval() const { 
		if(!suite) throw std::string("no suite");
		const Literal* returnVal = suite->eval(); 
		return returnVal;
}

const Literal* CallNode::eval() const {
	TableManager&  manager = TableManager::getInstance();
	
	manager.pushScope();
	
	string function_name = ident->getIdent();
	const FuncNode* function_impl = static_cast<const FuncNode*>( manager.getFunc(function_name) );	
	const Literal* returnVal = function_impl->eval();
	
	manager.popScope();
	
	return returnVal;
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
   const Literal* result = (*x)+(*y);
  return result;
  //return (*x).operator+(*y);
}

const Literal* SubBinaryNode::eval() const { 
  if (!left || !right) {
    throw "sub binary node error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* result = (*x)-(*y);
  return result;
}

const Literal* MulBinaryNode::eval() const { 
  if (!left || !right) {
    throw "mul error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* result = (*x)*(*y);
  return result;
}

const Literal* DivBinaryNode::eval() const { 
  if (!left || !right) {
    throw "div error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* result = (*x)/(*y);
  return result;
}

const Literal* DoubleSlashBinaryNode::eval() const { 
  if (!left || !right) {
    throw "double slash error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* result = (*x).operatorDoubleSlash(*y);
  return result;
}

const Literal* ModBinaryNode::eval() const { 
  if (!left || !right) {
    throw "mod error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* result = (*x).operator %(*y);
  return result;
}

const Literal* PowBinaryNode::eval() const { 
  if (!left || !right) {
    throw "pow error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* result = (*x).operatorPower(*y);
  return result;
}

const Literal* LessBinaryNode::eval() const { 
  if (!left || !right) {
    throw "less error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  const Literal* result = *x < *y;
  return result;
}

