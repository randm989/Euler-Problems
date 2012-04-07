
from math import pow

theSet=set()

for a in range(2,101):
	for b in range(2,101):
		result=pow(a,b)
		print result
		theSet.add(result)

print len(theSet)		

