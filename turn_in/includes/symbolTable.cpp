#include <map>
#include <algorithm>
#include "symbolTable.h"
#include "literal.h"
#include "node.h"
using std::endl;
using std::cout;

SymbolTable& SymbolTable::getInstance() {
  static SymbolTable instance;
  return instance;
}

const Literal* SymbolTable::getVar(const std::string& name) const {
  std::map<std::string, const Literal*>::const_iterator it = 
    vars.find(name);
  if ( it == vars.end() ) throw name+std::string(" not found");
  return it->second;
}
const Node* SymbolTable::getFunc(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it = 
    funcs.find(name);
  if ( it == funcs.end() ) throw name+std::string(" not found");
  return it->second;
}

void SymbolTable::setVar(const std::string& name, const Literal* var) { 
  //~ std::pair<std::string, const Literal*> temp(name, val);
  //~ table.insert(temp);
  vars[name] = var;
}
void SymbolTable::setFunc(const std::string& name, const Node* func) { 
  funcs[name] = func;
}

void SymbolTable::display(){
	cout << "vars: " << endl;
	for (auto i: vars){
		cout << i.first << " " << i.second << endl;
	}
	cout << "funcs: " << endl;
	for (auto i: funcs){
		cout << i.first << " " << i.second << endl;
	}
}
