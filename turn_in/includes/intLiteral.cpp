#include "literal.h"
#include <cmath>

 const Literal*IntLiteral::operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
 const Literal*IntLiteral::opPlus(float lhs) const  {
   const Literal*node = new FloatLiteral(static_cast<float>(val) + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
 const Literal*IntLiteral::opPlus(int lhs) const  {
   const Literal*node = new IntLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

 const Literal*IntLiteral::operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
 const Literal*IntLiteral::opSubt(float lhs) const  {
   const Literal*node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
 const Literal*IntLiteral::opSubt(int lhs) const  {
   const Literal*node = new IntLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

 const Literal*IntLiteral::operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
 const Literal*IntLiteral::opMult(float lhs) const  {
   const Literal*node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
 const Literal*IntLiteral::opMult(int lhs) const  {
   const Literal*node = new IntLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

 const Literal*IntLiteral::operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
 const Literal*IntLiteral::opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    float result = lhs/val;
   const Literal*node = new FloatLiteral(result);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
 const Literal*IntLiteral::opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    
    // match python's floor division for ints (eg -1/2 = -1 not 0)
   const Literal*node = new IntLiteral(floor((float) lhs / (float) val));
    
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  
 const Literal*IntLiteral::operatorDoubleSlash(const Literal& rhs) const {
	  return rhs.opDoubleSlash(val);
  }
  
 const Literal*IntLiteral::opDoubleSlash(float lhs) const {
	if ( val == 0 ) throw std::string("Zero Division Error");
	Literal* node = new FloatLiteral(floor(lhs / (float) val));
	PoolOfNodes::getInstance().add(node);
    return node;
  }
 
 const Literal*IntLiteral::opDoubleSlash(int lhs) const {
	if ( val == 0 ) throw std::string("Zero Division Error");
	Literal* node = new IntLiteral(floor( (float) lhs / (float) val));
	PoolOfNodes::getInstance().add(node);
    return node;
  }
  
 const Literal*IntLiteral::operator%(const Literal& rhs) const{
	  return rhs.opMod(val);
  }
 const Literal*IntLiteral::opMod(float lhs) const{
	if ( val == 0 ) throw std::string("Zero Division Error");
	float result =  std::fmod(lhs, val);
	if (result == -0.0) { result = 0.0; }; // python % never returns -0.0 or -0
	Literal* node = new FloatLiteral( result );
	PoolOfNodes::getInstance().add(node);
    return node;
  }
 const Literal*IntLiteral::opMod(int lhs) const{
	if ( val == 0 ) throw std::string("Zero Division Error");
	int result =  lhs % val;
	Literal* node = new IntLiteral( result );
	PoolOfNodes::getInstance().add(node);
    return node;
  }
  
 const Literal*IntLiteral::operatorPower(const Literal& rhs) const{
	return rhs.opPow(val);
  }
  
 const Literal*IntLiteral::opPow(float lhs) const{
	Literal* node = new FloatLiteral( pow(lhs, val) );
    PoolOfNodes::getInstance().add(node);
	return node;
  }
  
 const Literal*IntLiteral::opPow(int lhs) const{
	// both are ints, so return an int unless the exponent is negative
	Literal* node = NULL;
	if (val < 0){
	  node = new FloatLiteral( pow(lhs, val) );
	} else {
	  node = new IntLiteral( (int) pow(lhs, val) );
	}
	PoolOfNodes::getInstance().add(node);
	return node;
	  
  }
  
const Literal* IntLiteral::operator<(const Literal& rhs) const{
	return rhs.opLess(val);
}
const Literal* IntLiteral::opLess(float lhs_val) const{
	return lhs_val < val; 
}
const Literal* IntLiteral::opLess(int lhs_val) const{
	return lhs_val < val; 
}

  const Literal*IntLiteral::eval() const { return this; }
  void IntLiteral::print() const { 
    std::cout << val << std::endl; 
  }
  
void IntLiteral::display() const { cout << "IntLiteral" << val << endl; }
