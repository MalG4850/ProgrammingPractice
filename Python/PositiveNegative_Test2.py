num = int(input('Type a number to check if it is a positive or a negative integer: '))
if num > 0:
    reply = input('The number you typed is a positive number.')
    if num == 0:
        print('The number is 0.')
    else:
        print('The number is a positive number.')
else:
    print('The number is negative.')
