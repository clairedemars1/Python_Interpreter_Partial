#include <map>
#include <algorithm>
#include "symbolTable.h"
#include "literal.h"
using std::endl;
using std::cout;

SymbolTable& SymbolTable::getInstance() {
  static SymbolTable instance;
  return instance;
}

const Literal* SymbolTable::getValue(const std::string& name) const {
  std::map<std::string, const Literal*>::const_iterator it = 
    table.find(name);
  if ( it == table.end() ) throw name+std::string(" not found");
  return it->second;
}

void SymbolTable::setValue(const std::string& name, const Literal* val) { 
  //~ std::pair<std::string, const Literal*> temp(name, val);
  //~ table.insert(temp);
  table[name] = val;
}

void SymbolTable::display(){
	for (auto i: table){
		cout << i.first << " " << i.second << endl;
	}
}