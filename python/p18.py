#/bin/python

f = open('p18.txt','r')
contents = f.read()
f.close();

rows = contents.split("\n")
del rows[-1]
data = []

class unit:
  _num = 0
  aggregateNum = 0
  def __init__(self, num):
    self._num = num
  
  def __repr__(self):
    return str(self)

  def __str__(self):
    return "(" + str(self._num) + ", " + str(self.aggregateNum) + ")"

for s in rows:
  data.append([unit(int(num)) for num in s.split(" ")])


for y in xrange(len(data)):
  index = len(data) - y - 1
  for x in xrange(len(data[index])):
    entry = data[index][x]
    if index + 1 < len(data):
      entry.aggregateNum = max(data[index+1][x].aggregateNum, data[index+1][x+1].aggregateNum)
      entry.aggregateNum += entry._num
    else:
      entry.aggregateNum = entry._num
    #debug print
    #print x,index,entry

print "The maximum path total for this triangle is " + str(data[0][0].aggregateNum)
