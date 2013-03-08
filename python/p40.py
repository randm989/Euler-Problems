#!/usr/bin/python

#An irrational decimal fraction is created by concatenating the positive integers:
#
#  0.123456789101112131415161718192021...
#
#  It can be seen that the 12th digit of the fractional part is 1.
#
#  If dn represents the nth digit of the fractional part, find the value of the following expression.
#
#  d1 x d10 x d100 x d1000 x d10000 x d100000 x d1000000


#this is a tough one
#Stands for Champernowne's digit
def cDigit(index):

  #the number of digits per number in the current set
  d = 1
  startingNum = 0 
  #the first number is a funky case, since we have to account for 0
  subtractionValue = 10 

  #if the index we're searching for is in the ones, then we don't need to adjust the index
  #however if it's in the tens or above, we need to adjust our index appropriately, by upping our starting number and subtracting our index
  #so if it's 11, we subtract our starting index by ten (to account for the ten skipped digits, and up our starting number by 10
  
  #however the tens digit takes up two numbers each time, so we can find out how many digits it takes via this formula
  #d = the number of digits in each number for our current set
  # d * (10^d - 10^d-1)
  # the reason we subtract by 10^d-1 is to account for the digits we've subtracted from previous digit sets
  # so for all two digit numbers, d=2, it would take 2 * (10^2 - 10^1) = 180 digits total to contain all the numbers
  while index > d * (10**d - 10**(d-1)):
    startingNum = 10**d
    index -= subtractionValue
    d += 1
    subtractionValue = d * (10**d - 10**(d-1))

  #once we've found the appropriate index, find out which number the index is referring to by taking our starting number
  #and adding it with how many numbers deep we've calculated (using the adjusted index / the number of digits per number in our current set)
  #e.g. if our want to find the 103rd digit in the 3 digit numbers, 103/3 = 34, so we'd look at 100 + 34 = 134
  addend = int(index / d)
  #continuing from the last example, 103 % 3 = 1, so the remainder would be the digit of the exact number we've index to
  remainder = index % d

  #e.g. 103%3 = 1 so we look at the 2nd digit of 134, 3. The 103rd digit of the 3 digit numbers is 3
  return int(str(startingNum + addend)[remainder])


total = [1]

for x in range(1,7):
  total.append(cDigit(10**x))

print reduce(lambda x,y: x*y, total)


