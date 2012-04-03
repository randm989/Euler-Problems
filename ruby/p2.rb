#!/usr/bin/ruby


x=0
fib=1
fibprev=0

while fib < 4000000 do
	if fib % 2 == 0
		x += fib
	end
	fibtemp=fib
	fib+=fibprev
	fibprev=fibtemp	
end

puts "#{x}" 
