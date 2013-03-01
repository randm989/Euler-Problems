#In England the currency is made up of pound L and pence p and there are eight coins in general circulation:
#
#  1p, 2p, 5p, 10p, 20p, 50p, L1 (100p) and L2 (200p).
#  It is possible to make L2 in the following way:
#
#    1L1 + 150p + 220p + 15p + 12p + 31p
#    How many different ways can L2 be made using any number of coins?


currencyValues = (200,100,50,20,10,5,2,1)


def numCurrencyCombinations(values,index=0,currentSum=0):
	if currentSum >= 200 or index >= len(values):
		return 0
	iterations=int((200-currentSum)/int(values[index]))
	
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


print "The answer:",numCurrencyCombinations(currencyValues)

