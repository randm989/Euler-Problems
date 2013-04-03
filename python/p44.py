#!/usr/bin/python

#Pentagonal numbers are generated by the formula, Pn=n(3n1)/2. The first ten pentagonal numbers are:
#
#  1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...
#
#  It can be seen that P4 + P7 = 22 + 70 = 92 = P8. However, their difference, 70  22 = 48, is not pentagonal.
#
#  Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference are pentagonal and D = |Pk  Pj| is minimised; what is the value of D?
import math

nums = 10000

pentNums = []

for x in xrange(1,nums):
  pentNums.append( x * ( 3 * x - 1 ) / 2 )

def isPent(x):
  n = (math.sqrt(24*x+1)+1)/6
  return n == int(n)

D = 999999
for xi in xrange(1,len(pentNums)):
  x = pentNums[xi]
  for yi in xrange(1,x):
    y = pentNums[yi]
    if x + y > pentNums[-1]:
      break
    if x == y:
      continue

    if isPent(x + y):
      if isPent(abs(x-y)):
        D = abs(x-y)
        print "NEW D: ",D
        quit()