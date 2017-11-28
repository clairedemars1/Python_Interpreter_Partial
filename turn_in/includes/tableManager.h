#pragma once
#include <vector>
#include "symbolTable.h"


class TableManager {
public:
	static TableManager& getInstance();

	void setVar(const std::string& name, const Literal* var);
	void setFunc(const std::string&name, const Node* func);

	const Literal* getVar(const std::string& name) const;
	const Node* getFunc(const std::string& name) const;
	
	void pushScope();
	void popScope();
	
private:
	std::vector<SymbolTable> tables;
	int currentScope;
	TableManager(): tables(), currentScope(0) { 
		tables.push_back(SymbolTable());  // global scope
	}
};
