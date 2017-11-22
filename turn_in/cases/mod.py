# test if given types matter
print 5%3 # 2
print 5.0%3 #2.0
print 5%3.0 #2.0
print 5.0%3.0 #2.0

# test if resulting type matters (does it truncate)
print 4.3%2

# test negative zero
x = -3
x %= 3.0
print x
x = -3
x %= 3
print x


