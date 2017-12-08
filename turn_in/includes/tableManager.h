#pragma once
#include <vector>
#include "symbolTable.h"


class TableManager {
public:
	static TableManager& getInstance();

	void setVar(const std::string& name, const Literal* var);
	void setFunc(const std::string&name, const FuncNode* func);
	void setVarAsDefinedIfNotInLocalScope(const std::string& name);


	const Literal* getVar(const std::string& name) const;
	const Node* getFunc(const std::string& name) const;
	
	void pushScope();
	void popScope();
	
	void display() const;
	
private:
	std::vector<SymbolTable> tables;
	TableManager(): tables() { 
		tables.push_back(SymbolTable());  // global scope
	}
};
