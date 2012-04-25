#!/bin/python
import math

bignum = 2000000
sieve = set(xrange(bignum))

sieve.discard(0)
sieve.discard(1)


i = 2
while i < bignum:
	if i in sieve:
		sieve -= set([k*i for k in range(2,1+int(math.ceil(bignum/i)))])
	i+=1


print sum(sieve)
print len(sieve)
