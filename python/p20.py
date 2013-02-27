#/usr/bin/python

import math

result = 0

for i in str(math.factorial(100)):
  result += int(i)

print result
