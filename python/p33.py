#!/usr/bin/python

#The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
#
#We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
#
#There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
#
#If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

import myMath

def specialCancel(num,den):
	num_s = str(num)
	den_s = str(den)
	for index,c in enumerate(num_s):
		if c == den_s[0] and den_s[1] != '0':
			if float(num_s[(index+1)%2])/float(den_s[1]) == float(num)/den:
				return True
		if c == den_s[1] and den_s[0] != '0':
			if float(num_s[(index+1)%2])/float(den_s[0]) == float(num)/den:
				return True
	return False


exp = (specialCancel(i,k) for i in range(10,100) for k in range(10,100) if i/k < 1.0)

finalI = 1
finalK = 1

for i in range(10,100):
	for k in range(10,100):
		if i/k < 1.0 and i%10 != 0 and k % 10 != 0 and specialCancel(i,k):
			finalI *= i
			finalK *= k	


greatest = myMath.gcd(finalI,finalK)
print greatest,finalI,finalK
print finalI/greatest,finalK/greatest
