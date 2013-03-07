#!/usr/bin/python

#Take the number 192 and multiply it by each of 1, 2, and 3:
#
#  192  1 = 192
#  192  2 = 384
#  192  3 = 576
#  By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
#
#  The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
#
#  What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?



def pandigitalTest(num):
  numstr = ""
  i = 1
  while len(numstr) < 9:
    numstr = numstr + str(num*i)
    i+=1

  if len(numstr) == 9 and numstr.find('0') == -1 and all([numstr.count(str(x)) == 1 for x in range(1,10)]):
    return int(numstr)
  return 0

greatest = 0
for x in range(1,99999):
  greatest = max(greatest,pandigitalTest(x))

print greatest
