from datetime import date
d = int(input('Type the starting date: '))
m = int(input('Type the starting month: '))
y = int(input('Type the starting year: '))
d2 = int(input('Type the last day: '))
m2 = int(input('Type the last month: '))
y2 = int(input('Type the last year: '))
first_date = date(y,m,d)
last_date = date(y2,m2,d2)
result = last_date - first_date
print('This is the difference between the two days: ',result.days)
