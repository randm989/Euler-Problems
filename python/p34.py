#!/usr/bin/python

#145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
#
#Find the sum of all numbers which are equal to the sum of the factorial of their digits.
#
#Note: as 1! = 1 and 2! = 2 are not sums they are not included.

import math

facts = [math.factorial(x) for x in xrange(10)]
upperlimit = facts[9] * 8


def factCheck(num):
  num = str(num)
  numsum = 0
  for x in xrange(len(num)):
    numsum += facts[int(num[x])]
  return numsum == int(num)

answer = 0
for x in range(3,upperlimit):
  if factCheck(x):
    print x
    answer += x

print "The answer is %d" % (answer)
