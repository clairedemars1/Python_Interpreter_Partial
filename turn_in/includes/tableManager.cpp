#include "tableManager.h"

TableManager& TableManager::getInstance(){
	static TableManager instance;
	return instance;
}

const Literal* TableManager::getVar(const std::string& name) const {
  return tables[currentScope].getVar(name);
}
const Node* TableManager::getFunc(const std::string& name) const {
   return tables[currentScope].getFunc(name);
}

void TableManager::setVar(const std::string& name, const Literal* var) { 
	tables[currentScope].setVar(name, var);
}
void TableManager::setFunc(const std::string& name, const Node* func) { 
	tables[currentScope].setFunc(name, func);
}
