#By considering the terms in the fibonacci sequence whose values do not exceed four million, find the sum of the even valued terms

x = 0
fib = 1
fibprev = 0

while fib < 4000000:
	if fib % 2 == 0:
		x+=fib
	temp=fib
	fib+=fibprev
	fibprev=temp

print "answer = %d" % x
print "fib = %d fibprev = %d" % (fib, fibprev)

