
Singles = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
Teens = ['eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
Tens = ['ten', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']
Hundred = 'hundred'
Thousand = 'thousand'


def parseNum(num):
  thousands = ""
  hundreds = ""
  tens = ""
  singles = ""

  thousandsdigit = (num/1000)%10
  if thousandsdigit > 0:
    thousands = Singles[thousandsdigit-1] + Thousand

  hundredsdigit = (num/100)%10
  if hundredsdigit > 0:
    hundreds = Singles[hundredsdigit-1] + Hundred


  tensdigit = (num/10)%10
  onesdigit = num%10

  if hundredsdigit > 0 and (onesdigit > 0 or tensdigit > 0):
    hundreds += "and"

  if onesdigit > 0:
    singles = Singles[onesdigit-1]

  if tensdigit == 1 and onesdigit != 0:
    tens = Teens[onesdigit-1]
    singles = ""
  elif tensdigit >= 1:
    tens = Tens[tensdigit-1]
  
  return thousands + hundreds + tens + singles

lensum = 0
for x in range(1,1001):
  lensum += len(parseNum(x))
print lensum
