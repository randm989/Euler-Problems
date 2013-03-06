#!/usr/bin/python

#The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
#
#Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
#
#(Please note that the palindromic number, in either base, may not include leading zeros.)


def palindrome(string):
  strlen = len(string)
  count = int(strlen/2)
  for i in xrange(count):
    if string[i] != string[strlen-1-i]:
      return False

  return True


def testNum(num):
  strnum = str(num)
  if strnum[0] == '0' or strnum[-1] == '0':
    return False
  return palindrome(strnum) and palindrome(bin(num)[2:])

answer = 0
for i in range(1,1000000):
  if testNum(i):
    print i,bin(i)[2:]
    answer += i


print answer

