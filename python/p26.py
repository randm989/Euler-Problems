#!/usr/bin/python

def isCoprimeTo10(num):
	return num%2!=0 and num%5!=0

maxD=0
maxI=0
for i in range(2,1000):
	k = 1
	if isCoprimeTo10(i):
		while ((10**k) % i) != 1:
			k+=1
		if maxD < k:
			maxD = max(maxD,k)
			maxI = i
		print i,k

print maxI,maxD
