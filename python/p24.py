#!/usr/bin/python

#A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
#
#  012   021   102   120   201   210
#
#  What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

import math

numset = 10
possibleDigits = [x for x in xrange(numset)]
numAnswersFound = 0
answerFound = False

def numPush(digit,num):
  return (num*10) + digit

def numPop(num):
  return int(num/10) 

def recursiveAdvance(digitsRemaining, currentNum):
  global answerFound
  if answerFound:
    return

  global numAnswersFound
  global millionthAnswer
  if len(digitsRemaining) > 0:
    for i in range(len(digitsRemaining)):
      currentNum = numPush(digitsRemaining[i], currentNum)
      recursiveAdvance(digitsRemaining[:i] + digitsRemaining[i+1:], currentNum)
      currentNum = numPop(currentNum)
  else:
    numAnswersFound += 1
    #print (str(numAnswersFound) + " : %0" + str(numset) + "d") % currentNum
    if numAnswersFound == 1000000:
      print "The answer %d" % currentNum
      answerFound = True

recursiveAdvance(possibleDigits, 0)
