#!/usr/bin/ruby

def gcd(x,y)
	if y == 0 
		return x
	else
		return gcd(y,x%y)
	end

end

def lcm(x,y)
	return (x*y)/gcd(x,y)
end

x=1

for i in 1..20
	x=lcm(x,i)
	print "#{i}, #{x}\n"
end

