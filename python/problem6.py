#Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

import math


x = 0
y = 0

for i in range(1,101):
	x += i
	y += i*i

x=x*x

print x-y

