#!/usr/bin/python

#We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
#
#What is the largest n-digit pandigital prime that exists?

import myMath

poss = [x for x in range(1,8)]
largest = 0

while len(poss) > 2:
  perms = myMath.getAllPermutations(poss)
  for perm in perms:
    if perm > largest and myMath.isPrime(perm):
      largest = perm
  poss = poss[:-1]

print largest
