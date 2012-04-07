

i = 1
size=1001
total=1
cur=1
while 2*i+1 <= size:
	
	for j in range(0,4):
		cur+=2*i
		total+=cur
		print cur
	i+=1

print total

