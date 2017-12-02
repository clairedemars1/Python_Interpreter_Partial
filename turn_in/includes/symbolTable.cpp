#include <map>
#include <algorithm>
#include "symbolTable.h"
#include "literal.h"
#include "ast.h"
#include "node.h"
using std::endl;
using std::cout;

const Literal* SymbolTable::getVar(const std::string& name) const {
  std::map<std::string, const Literal*>::const_iterator it = 
    vars.find(name);
  if ( it == vars.end() ){
	   return &UndefLiteral::getInstance();
  }
  return it->second;
}
const Node* SymbolTable::getFunc(const std::string& name) const {
	std::map<std::string, const FuncNode*>::const_iterator it = 
		funcs.find(name);
	if ( it == funcs.end() ){
		   display();
		   return &UndefLiteral::getInstance();
	}
    return it->second;
}

bool SymbolTable::isPresentVar(const std::string& name) const {
	auto it = vars.find(name);
	return (it != vars.end() );
}

bool SymbolTable::isPresentFunc(const std::string& name) const {
	auto it = funcs.find(name);
	return (it != funcs.end() );
}

void SymbolTable::setVar(const std::string& name, const Literal* var) {
	vars[name] = var;
}
void SymbolTable::setFunc(const std::string& name, const FuncNode* func) { 
	func->display();
	funcs[name] = func;	
}

void SymbolTable::display() const {
	cout << "vars: " << endl;
	for (auto i: vars){
		cout << "	" << i.first << endl;
	}
	cout << "funcs: " << endl;
	for (auto i: funcs){
		cout << "	" <<  i.first << endl;
	}
}
