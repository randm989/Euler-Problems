#Find the largets palindrome made from the product of two 3-digit numbers

def isPalindrome(number):
	string = str(number)
	strlen = len(string)
	for i in range(0,strlen/2):
		if string[i] != string[strlen-i-1]:
			return False
	return True

x = isPalindrome(10023)
print x
x = isPalindrome(10101)
print x

for i in range(900,999):
	for j in range(900,999):
		if isPalindrome(i*j):
			print "%d and %d" % (i,j)
			print i*j

