#!/usr/bin/python

#A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
#
#  1/2 =   0.5
#  1/3 =   0.(3)
#  1/4 =   0.25
#  1/5 =   0.2
#  1/6 =   0.1(6)
#  1/7 =   0.(142857)
#  1/8 =   0.125
#  1/9 =   0.(1)
#  1/10  =   0.1
#  Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
#
#  Find the value of d  1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.



# A function to check if a number is shares no prime factors with ten, (the prime factors being 2 and 5)
def isCoprimeTo10(num):
	return num%2!=0 and num%5!=0

maxD=0
maxI=0

#iterate over every number in the range 2 to 1000
for i in range(2,1000):
	k = 1
        #if the current number shares no prime factors with ten
	if isCoprimeTo10(i):
                #this is where the math magic happens, iterate through powers of ten until a power of ten is divisible by the current number with a remainder of 1
		while ((10**k) % i) != 1:
			k+=1
                #the power of ten found is actually the length of the repeating pattern in the decimal.. pretty trippy math
		if maxD < k:
			maxD = max(maxD,k)
			maxI = i
		print i,k

print maxI,maxD
