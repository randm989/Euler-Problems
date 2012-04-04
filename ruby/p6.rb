#!/usr/bin/ruby

x=0
y=0

for i in 1..100
	x+=i
	y+=i*i
end
x = x*x

puts (y-x).abs
