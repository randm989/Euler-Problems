#!/usr/bin/ruby

#In the 20x20 grid below, four numbers along a diagonal line have been marked in red.
#
#What is the greatest product of four adjacent numbers in any direction (up, down, left, right, or diagonally) in the 2020 grid?


contents = File.read('p11.txt')

split = contents.split("\n")

split.map!{|s|
	s = s.split(" ")
	s.map!{|i| i.to_i}
	s
}

class NodeTraveler

	attr_accessor :debug

	def initialize(map)
		@map = map
		@xbound = map[0].length
		@ybound = map.length
		@debug = false
	end

	def TravelDirectionForProduct(xstep,ystep,ystart,xstart,steps)
		xPos = xstart
		yPos = ystart
		product = 1
		while self.CheckBounds(xPos,yPos) and steps > 0 do
			puts @map[yPos][xPos].class
			product *= @map[yPos][xPos]	
			xPos += xstep	
			yPos += ystep
			steps -= 1	
		end	
		return product
	end

	def CheckBounds(x,y)
		if x >= @xbound or x < 0
			return false	
		end
		if y >= @ybound or y < 0
			return false
		end	
		return true
	end
end

traveler = NodeTraveler.new(split)

puts traveler.TravelDirectionForProduct(1,1,0,1,2)
