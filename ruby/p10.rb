#!/usr/bin/ruby




sumOfPrimes = 2
listOfPrimes = [2]

for i in 3..2_000_000
	next if i % 2 == 0

	isPrime = true
	sqrti = Math.sqrt(i)
	listOfPrimes.each { |k|
		if i % k == 0
			isPrime = false
			break
		end
		if k > sqrti
			break
		end
	}
	if isPrime
		listOfPrimes.push(i)
		sumOfPrimes+=i
	end
end

puts sumOfPrimes
