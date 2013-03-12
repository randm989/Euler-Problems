#!/usr/bin/python

import myMath

poss = [x for x in xrange(10)]

primes = [1,2,3,5,7,11,13,17]
results = []
perms = myMath.getAllPermutations(poss)
for perm in perms:
  permStr = str(perm).zfill(10)
  i = 1
  passed = True
  while i < len(permStr)-2:
    if int(permStr[i] + permStr[i+1] + permStr[i+2]) % primes[i] != 0:
      passed = False
      break
    i+=1
  if passed:
    results.append(perm)

print "The answer is",sum(results)
