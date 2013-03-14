#!/usr/bin/python

t = 2
p = 2
h = 2

def T(n):
  return n * ( n + 1 ) / 2

def P(n):
  return n * ( 3 * n - 1 ) / 2

def H(n):
  return n * ( 2 * n - 1 )

tn = T(t)
pn = P(p)
hn = H(h)

answers = []
while len(answers) < 2:
  t+=1
  tn = T(t)
  while tn != pn or pn != hn:
    while tn < pn or tn < hn:
      t += 1
      tn = T(t)
  
    while pn < tn or pn < hn:
      p += 1
      pn = P(p)
  
    while hn < tn or hn < pn:
      h += 1
      hn = H(h)
    print tn,pn,hn

  answers.append(tn)
  print answers


print t,p,h,tn
