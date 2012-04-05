#!/usr/bin/ruby

#What is the value of the first triangle number to have over five hundred divisors
if ARGV.length < 1 
	puts "Takes a number as a parameter to calculate how many triangle numbers to put out"
	exit
end

def calculateTriangleNumbers(numToCalculate)
	triangleNums = [1]
	for i in 2..numToCalculate
		triangleNums.push(triangleNums[-1]+i)	
	end
	return triangleNums
end

calculateTriangleNumbers(ARGV[0].to_i).each_with_index {|i,index| puts "#{index}: #{i}"}
