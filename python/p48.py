#!/usr/bin/python

result = 0

for i in xrange(1,1001):
  result += i**i
  result %= 10**10
  print i,result
