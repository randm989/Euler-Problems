#!/usr/bin/python

def isLeapYear(year):
	return year%4==0 and (year%100!=0 or year%400==0)

def daysInMonth(month,year):
	if month in [3,5,8,10]:
		return 30
	elif month == 1:
		return isLeapYear(year) and 29 or 28 
	else:
		return 31

numSundays=0
day = 1 #the first day in 1901

for year in range(1901,2001):
	for month in range(0,12):
		day%=7
		if day == 6:
			numSundays+=1 
		day+=daysInMonth(month,year)

print numSundays
