#Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
#
#  21 22 23 24 25
#  20  7  8  9 10
#  19  6  1  2 11
#  18  5  4  3 12
#  17 16 15 14 13
#
#  It can be verified that the sum of the numbers on the diagonals is 101.
#
#  What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?


#the radius of the cube to the nearest edge
i = 1
#the goal diameter
size=1001

total=1
cur=1

#compare the current radius to the goal diameter
while 2*i+1 <= size:
  #calculate the 4 diagonal values for this radius value	
  for j in range(0,4):
    cur+=2*i
    total+=cur
    print cur
  #iterate to the next radius value
  i+=1

print total

