
'''
python is following this rule:
	go through whole function, and place all l-values (even ones in if statements) in the symbol table
	as declared but undefined, then go back to the top and actually run the statements
'''
x = 3 # necessary for all examples

def r(): # works
	print(x) 
	
def p(): # does not work
	x = x + 1
	
def g(): # does not work
	print(x)
	x = 1
	
def f(): # does not work
	print(x)
	if (3):
		x = 3
		
