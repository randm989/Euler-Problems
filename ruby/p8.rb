#!/usr/bin/ruby


contents = File.read('p8.txt') 

tracker=[]
highestProduct = 0

contents.each_char { |chr|
	tracker.unshift(chr.to_i)
	if tracker.length > 5
		tracker.pop
	end
	if tracker.length == 5
		product = 1
		tracker.each do |x|
			product *= x
		end
		highestProduct = [highestProduct,product].max
	end
}

puts highestProduct
