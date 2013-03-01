#!/usr/bin/python

#We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
#
#The product 7254 is unusual, as the identity, 39  186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
#
#Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
#
#HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.


def pandigitalProductCheck(multiplicand,multiplier,product):
  combined = str(multiplicand) + str(multiplier) + str(product)
  combinedLen = len(combined)
  if combinedLen != 9:
    return False

  combined = sorted(combined)
  if combined[0] != str(1) or combined[-1] != str(9):
    return False

  return all( combined[x] == str(x+1) for x in xrange(len(combined)))

solutionSet = set() 
associativeCache = {} 

for x in range(1,9876):
  for y in range(1,9876):
    if pandigitalProductCheck(x,y,x*y):
      print x,y,x*y
      if associativeCache.get(y,0) == x:
        print "The answer is: ", sum(solutionSet)
        quit()
      associativeCache[x] = y
      solutionSet.add(x*y)


