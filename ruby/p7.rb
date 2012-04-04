#!/usr/bin/ruby


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


i=0
cnt = 2
while i < 10001 do
	if isPrime(cnt)
		i+=1
		puts "#{i}, #{cnt}\n"
	end
	cnt+=1	
end
