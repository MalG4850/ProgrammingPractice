rows = int(input('Enter a number for the number of rows of stars: '))
for i in range(0,rows):
    for j in range(0,i + 1):
        print('*',end = ' ')
    print()
