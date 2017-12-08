x = 21
def f():
	x = 31
	def g():
		print x #prints 31
	g()
f()

x2 = 51
def f2():
	# no x here
	def g2():
		print x2 #prints 51
	g2()
f2()


def h():
	print x #prints 21

def p():
	x = 41
	h()
p()

print(x)
	
#does it work same for functions?
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
	
