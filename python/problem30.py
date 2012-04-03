

def sumOfDigitPower(num,power):
	numStr=str(num)
	total=0
	for i in numStr:
		total+=pow(int(i),power)
	return total

maxNum=pow(9,5)*5

total=0
for i in range(2,maxNum):
	temp=sumOfDigitPower(i,5)
	if i == temp:
		total+=temp
		print(i)


print total	
