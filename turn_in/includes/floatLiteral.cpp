  #include "literal.h"
  #include <cmath>
  
  using std::cout;
  using std::endl;
  
  Literal* FloatLiteral::operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  
  Literal* FloatLiteral::opPlus(float lhs) const  {
    Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node; 
  }
  
 Literal* FloatLiteral::opPlus(int lhs) const  {
    Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  Literal* FloatLiteral::operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  Literal* FloatLiteral::opSubt(float lhs) const  {
    Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  Literal* FloatLiteral::opSubt(int lhs) const  {
    Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  Literal* FloatLiteral::operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  Literal* FloatLiteral::opMult(float lhs) const  {
    Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  Literal* FloatLiteral::opMult(int lhs) const  {
    Literal* node = new FloatLiteral(static_cast<float>(lhs) * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  Literal* FloatLiteral::operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  Literal* FloatLiteral::opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    float result = lhs/val;
    Literal* node = new FloatLiteral( result );
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  Literal* FloatLiteral::opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    float result = lhs/val;
    Literal* node = new FloatLiteral(result);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  Literal* FloatLiteral::operatorDoubleSlash(const Literal& rhs) const {
	  return rhs.opDoubleSlash(val);
  }
  
  Literal* FloatLiteral::opDoubleSlash(float lhs) const {
	if ( val == 0 ) throw std::string("Zero Division Error");
	Literal* node = new FloatLiteral(floor(lhs / val));
	PoolOfNodes::getInstance().add(node);
    return node;
  }
 
  Literal* FloatLiteral::opDoubleSlash(int lhs) const {
	if ( val == 0 ) throw std::string("Zero Division Error");
	Literal* node = new FloatLiteral(floor( (float) lhs / val));
	PoolOfNodes::getInstance().add(node);
    return node;
  }
  
  Literal* FloatLiteral::operator%(const Literal& rhs) const{
	  return rhs.opMod(val);
  }
  Literal* FloatLiteral::opMod(float lhs) const{
	if ( val == 0 ) throw std::string("Zero Division Error");
	
	float result =  std::fmod(lhs, val);
	if (result == -0.0) { result = 0.0; }; // python % never returns -0.0 or -0
	
	Literal* node = new FloatLiteral( result );
	PoolOfNodes::getInstance().add(node);
    return node;
  }
  Literal* FloatLiteral::opMod(int lhs) const{
	if ( val == 0 ) throw std::string("Zero Division Error");
	
	float result =  std::fmod(lhs, val);
	if (result == -0.0) { result = 0.0; }; // python % never returns -0.0 or -0
	
	Literal* node = new FloatLiteral( result );	PoolOfNodes::getInstance().add(node);
    return node;
  }
  
  Literal* FloatLiteral::operatorPower(const Literal& rhs) const{
	return rhs.opPow(val);
  }
  
  Literal* FloatLiteral::opPow(float lhs) const{
	Literal* node = new FloatLiteral( pow(lhs, val) );
    PoolOfNodes::getInstance().add(node);
	return node;
  }
  
  Literal* FloatLiteral::opPow(int lhs) const{
	Literal* node = new FloatLiteral( pow(lhs, val) );
    PoolOfNodes::getInstance().add(node);
	return node;
  }
  
  const Literal* FloatLiteral::eval() const { return this; }
  
  void FloatLiteral::print() const { 
    int int_val = val;
    
    // print a float version of 5 as 5.0
	if ( (fabs(val-int_val) < 0.0000000001) &&
		fabs(val) >= abs(int_val) ){
		printf("%.1f", val);
		cout << endl;
	} else { // print regularly
		cout << val << endl;
	}
  }
