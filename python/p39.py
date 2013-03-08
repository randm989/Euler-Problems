#!/usr/bin/python

#If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
#
#{20,48,52}, {24,45,51}, {30,40,50}
#
#For which value of p  1000, is the number of solutions maximised?

numSolutions = [0] * 1001


for n in range(1,500):
  m = n+1
  while m < 500:
    a = m * m - n * n
    b = 2 * m * n
    c = m * m + n * n
    k = 1
    while k * (a + b + c) < 1000:
      numSolutions[k * (a+b+c)] += 1
      k += 1
    m+=2

maxSolution = (0,0)
for s in xrange(len(numSolutions)):
  if numSolutions[s] > maxSolution[1]:
    maxSolution = (s, numSolutions[s])

print "The answer is", maxSolution[0], "with", maxSolution[1], "answers"
