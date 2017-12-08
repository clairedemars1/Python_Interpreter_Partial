# malloy_proj4
Name: Claire DeMars

Clemson Email Address: cmdemar@clemson.edu

Project no: 4

Project due date: Dec. 8, 8am, 2017

Project description: add functions, relational operators, and if else to the ast

The easiest part of this project: 

Problems that I had in completing this project: a control-replace bug; 


Extra stuff:
- I made bools' and floats' output match Python's

- I made bool math work 
	eg (3==3)+2 evaluates to 1+2 or 3, but (3==3) evaluates to True
	I did it in an elegant way, using Justin's idea of BoolLiteral inheriting from IntLiteral, since doing so lets you use all of Int's math function implementations
	
- I think i made a good return strategy
	summary: 
		+I made the literals responsible for knowing if they were a return value or not and just asked them
		+ The trick was how to change a regular literal into a return literal, while keeping const and avoiding a screed of dynamic casts. To solve the problem, I used Timothy C.'s trick of making each literal class responsible for making a "return" version of itself.
	pros:
		+ it's pretty encapsulated, not altering any global variables (the symbol table)
		+ it doesn't necessitate removing a bunch of consts (the way my other strategy did)
		+ only requires changes in the literal classes
		+ it doesn't require dynamic casting
		

	
