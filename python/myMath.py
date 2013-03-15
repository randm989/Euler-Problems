#!/usr/bin/python
import math

primeSieve = []
primeSieveLen = 0

#Least common multiple calculation
def lcm(a,b):
	return (a*b)/gcd(a,b)

#Greatest common denominator calculation
def gcd(a,b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)

def isPandigital(num):
  strnum = str(num)
  numlen = len(strnum)
  return strnum.find('0') == -1 and all([strnum.count(str(x)) == 1 for x in range(1,numlen+1)])

#checks if a number is prime, pretty standard
def isPrime( num ):
  if num < primeSieveLen:
    return primeSieve[num]

  if num <= 1:
    return False

  sqrtNum = int(math.sqrt(num)) 
  for i in range(2,sqrtNum+1):
    if num % i == 0:
      return False
  return True


def initPrimeSieve(num):
  global primeSieve
  global primeSieveLen
  #limit the prime sieve to only use one megabyte of memory at most
  num = min(num, 1000000)
  primeSieve = [True] * num
  primeSieve[0] = primeSieve[1] = False
  for i in range(2,num):
    if primeSieve[i]:
      x = 2
      while x * i < num:
        primeSieve[x*i] = False
        x+=1
  primeSieveLen = len(primeSieve)
  return primeSieve


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

def getAllPermutations(digits):
  return _recursiveAllPermutations(digits,0)

def _recursiveAllPermutations(digits, cur):
  if len(digits) > 0:
    perms = []
    for i in range(len(digits)):
      cur = cur*10 + digits[i] #element push
      perms += _recursiveAllPermutations(digits[:i] + digits[i+1:], cur)
      cur = int(cur/10) #element pop
    return perms
  else:
    return [cur]
