year = int(input('Type a year to see if it is a leap year: '))
if year % 4 == 0:
    if year % 100 == 0:
        if year % 400 == 0:
            print('The year you typed is a leap year.')
    else:
        print('The year you typed is a leap year.')
else:
    print('The year you typed is not a leap year.')
input('Press enter to end the program: ')
