#!/usr/bin/python

#Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

f = open('../p13.txt')
contents = f.read()
f.close()

contents = contents.split("\n")

del contents[-1]
total = 0
for num in contents :
	total += int(num)

print str(total)[:10]
