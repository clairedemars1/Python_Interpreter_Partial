def f():
	x = 2
	print(x)
	def g():
		x = 3
		print(x)
	g()
f()

#it's calling g() when defining f: g is the asg node that's created
# so problem's in parse.y
