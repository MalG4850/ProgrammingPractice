rows = int(input('Enter the number of rows: '))
for i in range(rows,0,-1):
    print(i)
    for j in range(0,i + 1):
        print(j,end = ' ')
    print('\r')
    
