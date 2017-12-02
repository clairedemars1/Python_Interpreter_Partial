#ifndef SYMBOLTABLE__H
#define SYMBOLTABLE__H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

class Literal;
class FuncNode;
class Node;

class SymbolTable {
public:
  SymbolTable() : vars(), funcs() {}
  
  void setVar(const std::string& name, const Literal* var);
  void setFunc(const std::string&name, const FuncNode* func);
  
  bool isPresentVar(const std::string& name) const;
  bool isPresentFunc(const std::string& name) const;
  
  const Literal* getVar(const std::string& name) const;
  const Node* getFunc(const std::string& name) const;
  
  void	display() const;
private:
  std::map<std::string, const Literal*> vars;
  std::map<std::string, const FuncNode*> funcs;
};

#endif
