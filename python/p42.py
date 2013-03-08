#!/usr/bin/python

#The nth term of the sequence of triangle numbers is given by, tn = n/2*(n+1); so the first ten triangle numbers are:
#
#  1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
#
#  By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
#
#  Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?


def numVal(string):
  result = 0
  zeroval = ord('A') - 1
  for i in xrange(len(string)):
    result += ord(string[i]) - zeroval 

  return result


trinums = []
for x in range(1,50):
  trinums.append(int((x/2.0)*(x+1)))

f = open('p42.txt','r')
contents = f.read()
f.close();

contents = contents.replace("\"","")
rows = contents.split(",")
del rows[-1]

answer = 0
for name in rows:
  if numVal(name) in trinums:
    answer += 1

print answer
