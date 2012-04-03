#!/usr/bin/ruby

def isPalindrome(num)
	str=num.to_s()
	for x in 0..str.length/2 
		if str[x] != str[-x-1]
			return false
		end
	end
	return true
end

smallestMultiplier = 0
solution=0

999.downto(100) do |i|
	999.downto(100) do |k|
		puts "#{i},#{k}" 
		if isPalindrome(i*k)
			if i*k > solution
				solution=i*k
			end
			smallestMultiplier=[i,k].min()
			break
		end	
		if k < smallestMultiplier
			break
		end
	end
	if solution != 0 and i < smallestMultiplier
		break
	end
end

puts solution
