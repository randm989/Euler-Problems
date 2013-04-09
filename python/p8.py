#!/usr/bin/python

# I think this is the one where you have to find the highest product of any 5 digits in a row in the list

f = file('../p8.txt')
txt = f.read()
f.close()

txt = txt.strip()


length=len(txt)

print max([reduce(lambda x,y: int(x)*int(y), txt[i-5:i]) for i in range(5,length)]) 

