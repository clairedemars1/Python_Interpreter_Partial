def f():
	x = 2
	print(x)
	def g():
		x = 3
		print(x)
	g()
f()
