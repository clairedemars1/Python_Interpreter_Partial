#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <map>
#include <typeinfo>
#include "literal.h"
#include "tableManager.h"

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

class IfNode: public Node {
public:
	IfNode(const Node* _test, const Node* _ifSuite, const Node* _elseSuite): 
		test(_test)
		,ifSuite(_ifSuite)
		,elseSuite(_elseSuite)
	 {}
	IfNode(const IfNode&)=delete;
	IfNode& operator=(const IfNode&)=delete;
	virtual const Literal* eval() const;
	virtual void display() const {cout << "IfNode, incomplete display" << endl;}
private:
	const Node* test;
	const Node* ifSuite;
	const Node* elseSuite;
};

class ReturnNode: public Node {
public:
	ReturnNode(const Node* _returnMe): Node(), returnMe(_returnMe){ }
	ReturnNode(): Node(), returnMe( &(NoneLiteral::getInstance()) ){ }
	~ReturnNode(){}
	ReturnNode(const ReturnNode&)=delete;
	ReturnNode& operator=(const ReturnNode&)=delete;
	virtual const Literal* eval() const;
	virtual void display() const;
private:
	const Node* returnMe;
	
};

class PrintNode: public Node {
public:
	PrintNode(const Node* _printMe): Node(), printMe(_printMe){ }
	~PrintNode(){}
	PrintNode(const PrintNode&)=delete;
	PrintNode& operator=(const PrintNode&)=delete;
	virtual const Literal* eval() const;
	virtual void display() const;
private:
	const Node* printMe;

};
class IdentNode : public Node {
public:
  IdentNode(const std::string& id) : Node(), ident(id) {
  } 
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
  virtual void display() const;

private:
  const std::string ident;
};

// suite of code statements for a function
class SuiteNode: public Node {
public:
	SuiteNode(): Node(), statements() {}
	~SuiteNode() {}
	SuiteNode(const SuiteNode&)=delete;
	SuiteNode& operator=(const SuiteNode&)=delete;
	virtual const Literal* eval() const;
	void addStatement(const Node*);
	virtual void display() const;

private:
	std::vector<const Node*> statements;
};

// function definition: code and params
class FuncNode: public Node {
public:
	FuncNode(SuiteNode* _suite, int _enclosingScopeIndex): 
		suite(_suite)
		,enclosingScopeIndex(_enclosingScopeIndex) { }
	~FuncNode(){}
	FuncNode(const FuncNode&)=delete;
	FuncNode& operator=(const FuncNode&)=delete;
	virtual const Literal* eval() const;
	virtual void display() const { cout << "FuncNode" << endl; if (suite) suite->display(); }
	int getEnclosingScopeIndex() const { return enclosingScopeIndex; }
private:
	SuiteNode* suite;
	int enclosingScopeIndex;
	// todo params
};

// assign a definition to a function name
// 		different from AsgBinaryNode b/c it has to call setFunc from the tableManager not setVar
class FuncAsgNode: public Node {
public:
	FuncAsgNode(const IdentNode* _ident, FuncNode* _func):
		ident(_ident)
		,func(_func)
		{ }
	~FuncAsgNode(){}
	FuncAsgNode(const FuncAsgNode&)=delete;
	FuncAsgNode& operator=(const FuncAsgNode&)=delete;
	virtual const Literal* eval() const;
	virtual void display() const;

private:
	const IdentNode* ident;
	const FuncNode* func;	
}; 


class CallNode: public Node {
public:
	CallNode(const IdentNode* _ident): Node(), ident(_ident){}
	~CallNode(){}
	CallNode(const CallNode&)=delete;
	CallNode& operator=(const CallNode&)=delete;
	virtual const Literal* eval() const;
	virtual void display() const;
private:
	const IdentNode* ident;
};

class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  virtual ~BinaryNode() {}
  virtual const Literal* eval() const = 0;
  Node* getLeft()  const { return left; }
  Node* getRight() const { return right; }
  BinaryNode(const BinaryNode&) = delete;
  BinaryNode& operator=(const BinaryNode&) = delete;
  virtual void display(){ cout << typeid(*this).name() << endl; }
protected:
  Node *left;
  Node *right;
private:
};

class AsgBinaryNode : public BinaryNode {
public:
  AsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class DoubleSlashBinaryNode : public BinaryNode {
public:
  DoubleSlashBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class ModBinaryNode : public BinaryNode {
public:
  ModBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class PowBinaryNode : public BinaryNode {
public:
  PowBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class LessBinaryNode: public BinaryNode {
public:
	LessBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
	virtual const Literal* eval() const; 
};

class LessEqualBinaryNode: public BinaryNode {
public:
	LessEqualBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
	virtual const Literal* eval() const; 
};

class GreaterBinaryNode: public BinaryNode {
public:
	GreaterBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
	virtual const Literal* eval() const; 
};

class GreaterEqualBinaryNode: public BinaryNode {
public:
	GreaterEqualBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
	virtual const Literal* eval() const; 
};

class EqualEqualBinaryNode: public BinaryNode {
public:
	EqualEqualBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
	virtual const Literal* eval() const; 
};

class NotEqualBinaryNode: public BinaryNode {
public:
	NotEqualBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
	virtual const Literal* eval() const;
};


