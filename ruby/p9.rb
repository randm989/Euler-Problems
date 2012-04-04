#!/usr/bin/ruby


m = 1
n = 1 
k = 1

result = 0

while m<1000 do
	
	for n in 1..m-1
		a = m*m - n*n
		b = 2*m*n
		c = m*m + n*n
		if 1000 % (a+b+c) == 0
			k = 1000 / (a+b+c)
			puts "K: ",k, "\nA: ", a, "\nB: ", b, "\nC: ", c, "\nABC: ", k*a*k*b*k*c
			exit
		end
	end
	m+=1
end


