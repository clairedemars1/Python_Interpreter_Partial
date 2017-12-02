#include <iostream>
#include "tableManager.h"
#include "literal.h"
using std::cout;
using std::endl;

TableManager& TableManager::getInstance(){
	static TableManager instance;
	return instance;
}

const Literal* TableManager::getVar(const std::string& name) const {
	int currentScope = tables.size();
	while(currentScope >= 0){
		bool isInCurrentScope = tables[currentScope].isPresentVar(name);
		if (isInCurrentScope){
			return tables[currentScope].getVar(name);
		} else {
			currentScope--;
		}
	}
	throw std::string("NameError: name '"+name+"' is not defined");
}
const Node* TableManager::getFunc(const std::string& name) const {
  	int currentScope = tables.size();
	while(currentScope >= 0){
		bool isInCurrentScope = tables[currentScope].isPresentFunc(name);
		if (isInCurrentScope){
			return tables[currentScope].getFunc(name);
		} else {
			currentScope--;
		}
	}
	throw std::string("NameError: name '"+name+"' is not defined");
}

void TableManager::setVar(const std::string& name, const Literal* var) { 
	int currentScope = tables.size();
	tables[currentScope].setVar(name, var);
}
void TableManager::setFunc(const std::string& name, const FuncNode* func) { 
	int currentScope = tables.size();
	cout << currentScope << endl;
	tables[currentScope].setFunc(name, func);
}

void TableManager::pushScope(){
	tables.push_back( SymbolTable() );
	cout << "pushed a scope" << endl;
}

void TableManager::popScope(){
	tables.pop_back();
	cout << "popped a scope" << endl;
}

void TableManager::display() const {
	for (auto t: tables){
		t.display();
	}
}
