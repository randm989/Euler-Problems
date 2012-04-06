#!/usr/bin/ruby

#What is the value of the first triangle number to have over five hundred divisors

def numDivisors(x)
	sqrtx = Math.sqrt(x)
	i = 1
	numDiv = 0
	divisorList = []
	while i <= sqrtx
		if x%i==0
			numDiv+=(i==sqrtx)?1:2
			divisorList.push(x/i,i)
		end
		i+=1
	end
	puts divisorList.uniq.sort.join(',')
	return numDiv
end

for i in 2..20
	puts i.to_s + ": " + numDivisors(i).to_s
	puts
end
exit

triNum = 1
triAdder = 2

while numDivisors(triNum) < 500
	triNum+=triAdder
	triAdder+=1
end

puts triNum

