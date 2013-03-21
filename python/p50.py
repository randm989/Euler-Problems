#!/usr/bin/python

import myMath

myMath.initPrimeSieve(1000000)

primes = [x for x in xrange(1000000) if myMath.isPrime(x)]

answer = 0
mostConsecutive = 0

for i in xrange(len(primes)):
  j = 1
  cursum = primes[i]
  while i+j < len(primes) and cursum < 1000000:
    cursum+=primes[i+j]
    if myMath.isPrime(cursum) and j > mostConsecutive:
      answer = cursum
      mostConsecutive = j
    j+=1

print answer
