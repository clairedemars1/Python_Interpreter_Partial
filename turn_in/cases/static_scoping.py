x = 2
def f():
	x = 3
	def g():
		print x #prints 3
	g()
f()


def h():
	print x #prints 2

def p():
	x = 4
	h()
p()
	
	#~ 
#~ x = 2
#~ 
#~ def qu():
	#~ print 5
#~ 
#~ def f():
	#~ x = 3
	#~ def qu():
		#~ print 6
	#~ def g():
		#~ print x #prints 3
	#~ qu()
	#~ g()
#~ f()
#~ print
#~ 
#~ def h():
	#~ def qu():
		#~ print 7
	#~ print x #prints 2
	#~ qu()
#~ 
#~ def p():
	#~ x = 4
	#~ def qu():
		#~ print 8
	#~ qu()
	#~ h()
#~ p()
	
