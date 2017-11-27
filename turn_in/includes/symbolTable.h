#ifndef SYMBOLTABLE__H
#define SYMBOLTABLE__H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

class Literal;
class Node;

class SymbolTable {
public:
  //~ static   SymbolTable& getInstance();
  
  void setVar(const std::string& name, const Literal* var);
  void setFunc(const std::string&name, const Node* func);
  
  const Literal* getVar(const std::string& name) const;
  const Node* getFunc(const std::string& name) const;
  
  void		display();
private:
  std::map<std::string, const Literal*> vars;
  std::map<std::string, const Node*> funcs;
  SymbolTable() : vars(), funcs() {}
};

#endif
