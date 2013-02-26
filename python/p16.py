# 215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

# What is the sum of the digits of the number 21000?

import math
num = str(2 ** 1000)
numSum = 0
for i in range(len(num)):
  numSum += int(num[i])

print numSum
