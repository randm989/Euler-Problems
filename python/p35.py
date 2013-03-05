#!/usr/bin/python

#The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
#
#There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
#
#How many circular primes are there below one million?
import myMath

resultSieve = bytearray(1000001)

def rotateDigits(num):
  carried = num%10
  return int(str(carried) + str(int(num/10)))


for i in range(2,len(resultSieve)):
  if resultSieve[i] != 0 or any([x == '0' for x in str(i)]):
    continue

  variations = [i]
  success = myMath.isPrime(i)
  rotated = i
  for x in xrange(len(str(i))-1):
    rotated = rotateDigits(rotated)
    variations.append(rotated)
    success = success and myMath.isPrime(variations[x+1])

  for x in variations:
    resultSieve[x] = 2 if success else 1
  
answer = 0

for x in resultSieve:
  if x == 2:
    answer+=1

print "The answer is", answer
