import math


def isprime( num ):
	if num < 0:
		return False
	i = 2
	while i < math.sqrt(num):
		if num % i == 0:
			return False
		i+=1
	return True

maxPrimes=0

for a in range(-999,1000):
	for b in range(-999,1000):
		n=0
		while isprime(n*n+a*n+b):
			n+=1
		if n > maxPrimes:
			maxPrimes=n
			print "%d: a=%d b=%d" % (maxPrimes,a,b)

print "%d: a=%d b=%d" % (maxPrimes,a,b)
