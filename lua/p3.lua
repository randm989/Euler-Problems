#!/usr/bin/ruby


x = 600851475143

function isPrime(num)
	local i = 2
	local numroot = math.sqrt(num)
	while i <= numroot do
		if num % i == 0 then
			return false
		end
		i=i+1
	end
	return true
end

sqrtx = math.sqrt(x)

i = math.floor(sqrtx)

while i > 2 do
	if x % i == 0 and isPrime(i) then
		break
	end
	i=i-1
end

print (i,'is the final answer')
