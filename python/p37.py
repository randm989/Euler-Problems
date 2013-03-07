#!/usr/bin/python

#The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
#
#Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
#
#NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
import myMath

possibilities = [[2,3,5,7]]
answers = set([])

def rightToLeftTest(strnum):
  for x in xrange(len(strnum)-1):
    if myMath.isPrime(int(strnum[:-x-1])) == False:
      return False
  return True

def prependPrimerDigit(num):
  result = set() 
  for i in range(1,10):
    candidate = str(i)+str(num)
    if myMath.isPrime(int(candidate)):
      result.add(int(candidate))
  return result

i = 0

while len(answers) < 11:
  possibilities.append(set([]))
  for x in possibilities[i]:
    primed = prependPrimerDigit(x)
    for prime in primed:
      if rightToLeftTest(str(prime)):
        answers.add(prime)
    possibilities[i+1] = possibilities[i+1].union(primed)
  i+=1

print sum(answers)
