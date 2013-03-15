#!/usr/bin/python

import myMath

#my first solution, better solution found in forum

count = 1
start = 0
target = 4 
maxlimit = 1000000
sieve = [True] * maxlimit

for i in xrange(maxlimit):
  mult = myMath.getMultiplicities(i) 
  if sieve[i] == True and len(mult) == target:
    count += 1 
    if count > 1:
      print i,count
    if count == 1:
      start = i
    if count == target:
      break
  else:
    if sieve[i] == True:
      for x in mult.items():
        numToIter = i
        while numToIter < maxlimit:
          sieve[numToIter] = False
          numToIter *= x[0]
    count = 0


print start
