#include "tableManager.h"

TableManager& TableManager::getInstance(){
	static TableManager instance;
	return instance;
}

const Literal* TableManager::getVar(const std::string& name) const {
  return tables[currentScope].getVar(name); // todo check other scopes
}
const Node* TableManager::getFunc(const std::string& name) const {
   return tables[currentScope].getFunc(name);// todo check other scopes
}

void TableManager::setVar(const std::string& name, const Literal* var) { 
	tables[currentScope].setVar(name, var);
}
void TableManager::setFunc(const std::string& name, const FuncNode* func) { 
	tables[currentScope].setFunc(name, func);
}

void TableManager::pushScope(){
	tables.push_back( SymbolTable() );
}

void TableManager::popScope(){
	tables.pop_back();
}

void TableManager::display(){
	for (auto t: tables){
		t.display();
	}
}
