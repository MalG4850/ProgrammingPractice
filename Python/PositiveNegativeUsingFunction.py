def PositiveNegative(y):
    if(y > 0):
        print('This is a positive number.')
    elif(y < 0):
        print('This is a negative number.')
    elif(y == 0):
        print('0 is neither a positive number nor a negative number.')

PositiveNegative(int(input('Type a number to see if it is a positive or a negative integer.')))
