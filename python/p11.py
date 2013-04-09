#!/usr/bin/python


f = open('../p11.txt','r')
contents = f.read()
f.close();

rows = contents.split("\n")
del rows[-1]
data = []
for s in rows:
	data.append([int(num) for num in s.split(" ")])	


class NodeTraversal:
	directions = [[1,1],[1,0],[1,-1],[0,1],[0,-1],[-1,1],[-1,0],[-1,-1]]
	d = []
	def __init__(self, d):
		self.d = d 

	def traverse(self):
		maxProd = 0
		for i in xrange(len(self.d)):
			for k in xrange(len(self.d[i])):
				nodeResult = max([self._traverse(di,[i,k]) for di in self.directions])
				maxProd = max(nodeResult,maxProd)
		return maxProd

	def _traverse(self,di,node):
		result = self.val(node[0],node[1])
		numIter = 3
		while numIter > 0:
			node = [sum(pair) for pair in zip(node,di)]
			print node
			if ( self.boundsCheck(node[0],node[1]) ):
				result *= self.val(node[0],node[1])	
				numIter -= 1
			else:
				break
		return result

	def boundsCheck(self,row,column):
		if ( row < 0 or row >= len(self.d) or column < 0 or column >= len(self.d[row]) ):
			return False
		return True

	def val(self,row,column):
		return self.d[row][column]


n = NodeTraversal(data)

print n.traverse()
