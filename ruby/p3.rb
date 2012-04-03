#!/usr/bin/ruby


x = 600851475143

def isPrime(num)
	i = 2
	numroot = Math.sqrt(num)
	while i <= numroot do
		if num % i == 0
			return false
		end
		i+=1
	end
	return true
end

sqrtx = Math.sqrt(x)
$i = sqrtx.floor
while $i > 2 do
	if x % $i == 0 and isPrime($i)
		break
	end
	$i-=1
end

puts "#{$i} is the final answer"
