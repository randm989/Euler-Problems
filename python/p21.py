#/usr/bin/python

#Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
#If d(a) = b and d(b) = a, where a  b, then a and b are an amicable pair and each of a and b are called amicable numbers.
#
#For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
#
#Evaluate the sum of all the amicable numbers under 10000.

import math

amicable = [0] * 10000

def findAmicableSum(num):
  result = 1
  #divisors = ""
  for i in range(2,int(math.ceil(math.sqrt(num)))):
    if num%i == 0:
      result += i + (num / i)
      #divisors += str(i) + "," + str(num/i) + " "

  #debug information
  #print str(num) + ": " + divisors

  return result

answer = 0
amicable[1] = 1

for i in range(2,10000):
  cur = amicable[i]
  if amicable[i] == 0:
    amicable[i] = findAmicableSum(i)
    cur = amicable[i]
    #print i,cur
  if cur < 10000: 
    if amicable[cur] == 0: 
      amicable[cur] = findAmicableSum(cur)
      #print "\t",cur,amicable[cur]
    if amicable[cur] == i and cur != amicable[cur]:
      answer += i 
      #print "answer ",str(cur),str(amicable[cur])

print answer
