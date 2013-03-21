#!/usr/bin/python

import myMath

myMath.initPrimeSieve(10000)

def digits(num):
  return [int(dig) for dig in str(num)] 

def findArithmeticSequence(numSet):
  if len(numSet) >= 3:
    numSet = sorted(numSet)
    for x in numSet:
      numSetCopy = numSet[:]
      numSetCopy.remove(x)
      for y in numSetCopy:
        diff = abs(y-x)
        if y + diff in numSetCopy: 
          return (x,y,y+diff)
  return ()

answers = []

for i in xrange(1001,10000):
  perms = list(set(myMath.getAllPermutations(digits(i))))
  perms = [x for x in perms if myMath.isPrime(x) and x > 1000]
  result = findArithmeticSequence(perms)
  if result != () and result not in answers:
    print result
    answers.append(result)

