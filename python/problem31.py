import math

currencyValues = (200,100,50,20,10,5,2,1)


def numCurrencyCombinations(values,index=0,currentSum=0):
	if currentSum >= 200 or index >= len(values):
		return 0
	iterations=int((200-currentSum)/math.floor(values[index]))
	
	tempSum=currentSum
	numCombinations = 0
	while iterations >= 0:
		tempSum=currentSum
		tempSum+=values[index]*iterations
		if tempSum == 200:
			numCombinations+=1
		numCombinations+=numCurrencyCombinations(values,index+1,tempSum)
		iterations-=1
	return numCombinations


print numCurrencyCombinations(currencyValues)

