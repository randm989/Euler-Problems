#!/usr/bin/python

#Calculates the multiplicities of a number (how many times each prime factor needs to be multiplied to achieve the desired number)
def getMultiplicities(num):
  i = 2
  result = {}
  while i <= num:
    #if the current iterator dives cleanly into the given number
    while num % i == 0:
      #add that number as a multiplicity and divide the total number by it
      if result.has_key(i) == False:
        result[i] = 0
      result[i] += 1
      num /= i
    i+=1	
  return result
	

#Given a set of multiplicites of a number, it will calculate all the possible divisors, based on those multiplicities
def getDivisorsByMultiplicities(multiplicities):
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

def getDivisors(num):
  return getDivisorsByMultiplicities(getMultiplicities(num))


