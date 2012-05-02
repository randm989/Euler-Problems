#!/usr/bin/python


f = open('p11.txt','r')
contents = f.read()
f.close();

rows = contents.split("\n")
del rows[-1]
data = []
for s in rows:
	data.append([int(num) for num in s.split(" ")])	

print data



class NodeTraversal:
	directions = [[1,1],[1,0],[1,-1],[0,1],[0,-1],[-1,1],[-1,0],[-1,-1]]
	d = []
	def __init__(self, d):
		self.d = d 

	def traverse(self):
		maxProd = 0
		for i in len(self.d):
			for k in len(i):
				nodeResult = max([self._traverse(di,[i,k]) for di in directions])

	def _traverse(self,di,node):
		result = self.val(node[0],node[1])
		numIter = 3
		while numIter > 0:
			node = [sum(pair) for pair in zip(node,di)]
			result *= self.val(node[0],node[1])	
			numIter -= 1
		return result

	def val(self,row,column):
		return self.d[row][column]


n = NodeTraversal(data)

print n._traverse([0,1],[0,0])
