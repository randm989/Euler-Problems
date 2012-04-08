#!/usr/bin/python

def isPrime(num):
	i=2
	while i*i <= num:
		if num%i==0:
			return False
		i+=1
	return True	


i=0
cnt=2
while i < 10001:
	if isPrime(cnt):
		i+=1
		print i,cnt
	cnt+=1	

