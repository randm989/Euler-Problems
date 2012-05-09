#!/usr/bin/python

#The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
#
#1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
#
#Let us list the factors of the first seven triangle numbers:
#
# 1: 1
# 3: 1,3
# 6: 1,2,3,6
#10: 1,2,5,10
#15: 1,3,5,15
#21: 1,3,7,21
#28: 1,2,4,7,14,28
#We can see that 28 is the first triangle number to have over five divisors.
#
#What is the value of the first triangle number to have over five hundred divisors?

def getMultiplicities(num):
	i = 2
	result = {}
	while i <= num:
		if num % i == 0:
			if result.has_key(i) == False:
				result[i] = 0
			result[i] += 1
			num /= i
			i = 1
		i+=1	
	return result
	


def getDivisors(multiplicities):
	primeFactors = multiplicities.items()
	exp = [0] * len(primeFactors)
	
	result = []
	explen = len(exp)

	while True:	
		k = 0
		result += [reduce(lambda x,y: x*y, [primeFactors[i][0]**exp[i] for i in range(explen)],1)]
		while True:
			exp[k] += 1
			if exp[k] <= primeFactors[k][1]:
				break
			exp[k] = 0
			k+=1
			if k >= explen:
				return result


triNum = 1
triIter = 2
factors = [1]
while len(factors) <= 500:
	triNum+=triIter
	triIter+=1
	factors = getDivisors(getMultiplicities(triNum))

print triNum,len(factors),factors
