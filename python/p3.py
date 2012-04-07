#What is the largets prime factor of the number 600851475143
import math

def isprime( num ):
	i = 2
	while i < math.sqrt(num):
		if num % i == 0:
			return False
		i+=1
	return True


x = 600851475143
sqrtx = math.floor(math.sqrt(x))

j = sqrtx
while j > 1:
	if x % j == 0 and isprime(j):
		print j
		break
	j-=1

print j


