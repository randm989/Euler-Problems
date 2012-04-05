#!/usr/bin/ruby

#In the 20x20 grid below, four numbers along a diagonal line have been marked in red.
#
#What is the greatest product of four adjacent numbers in any direction (up, down, left, right, or diagonally) in the 2020 grid?


contents = File.read('p11.txt')

split = contents.split("\n")

for s in split
	s = s.split(" ")
end

puts split

class NodeTraveler
	def initialize(map)
		@map = map
		@xbound = map[0].length
		@ybound = map.length
	end

	def TravelDirection(xstep,ystep,ystart,xstart)
		xPos = xstart
		yPos = ystart
			
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

