#pragma once

//~ #include "literal.h"

class LiteralMaker {
	public:
		Literal* makeLiteral(int i){
			return new IntLiteral(i);
		}
		Literal* makeLiteral(float f){
			return new FloatLiteral(f);
		}
};

