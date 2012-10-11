#!/usr/bin/python

import sys


# It's all about pascal's triangle
sizeOfGrid=20
if len(sys.argv) > 1:
  sizeOfGrid = int(sys.argv[1])

TriangleRows = [[1]]

for i in range(1,sizeOfGrid*2+1):
  TriangleRows.append([1])
  for j in range(1,len(TriangleRows[i-1])+1):
    if j == len(TriangleRows[i-1]):
      TriangleRows[i].append(1)
    else:
      TriangleRows[i].append(TriangleRows[i-1][j] + TriangleRows[i-1][j-1])


print "The Number of possible ways to traverse a grid of a given size\nSize\tSolutions"

for i in TriangleRows:
  if len(i) % 2 == 1:
    index = int(len(i)/2)
    print str(index) + "\t" + str(i[index])
