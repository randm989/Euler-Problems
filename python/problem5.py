#find the least common multiple of all numbers 1-20

	
def gcd(a,b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)


def lcm(a,b):
	return (a*b)/gcd(a,b)

x = 1

for i in range(1,21):
	x = lcm(x,i)
	print i

print x

