#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <map>
#include "literal.h"
#include "tableManager.h"

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

class IdentNode : public Node {
public:
  IdentNode(const std::string& id) : Node(), ident(id) {
  } 
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
  //~ bool operator==(const IdentNode* rhs) const {
	  //~ return this->ident == rhs->ident;
  //~ }
  //~ bool operator==(const IdentNode& rhs) const {
	  //~ return this->ident == rhs.ident;
  //~ }
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
private:
	std::vector<const Node*> statements;
};

class FuncNode: public Node {
public:
	FuncNode(const IdentNode* _ident, SuiteNode* _suite):
		ident(_ident)
		,suite(_suite)
	{
		//~ TableManager::getInstance().setFunc(name, suite);
	}
	~FuncNode(){}
	FuncNode(const FuncNode&);
	FuncNode& operator=(const FuncNode&);
	void addStatement(const Node*);
	virtual const Literal* eval() const;
private:
	const IdentNode* ident;
	const SuiteNode* suite;	
}; 

class CallNode: public Node {
public:
	CallNode(const IdentNode* _ident): Node(), ident(_ident){}
	~CallNode(){}
	CallNode(const CallNode&)=delete;
	CallNode& operator=(const CallNode&)=delete;
	virtual const Literal* eval() const;
private:
	const IdentNode* ident;
};

class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r), is_neg(false) {}
  virtual const Literal* eval() const = 0;
  Node* getLeft()  const { return left; }
  Node* getRight() const { return right; }
  BinaryNode(const BinaryNode&) = delete;
  BinaryNode& operator=(const BinaryNode&) = delete;
  virtual void changeSign(){
	is_neg = !is_neg;
  }
  virtual bool isNegative() const {
	return is_neg;
  }
protected:
  Node *left;
  Node *right;
private:
  bool is_neg;
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

