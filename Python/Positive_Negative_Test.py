num = int(input('Type a number to check if a number is a positive or a negative integer: '))
if num > 0:
    reply = input('The number you typed is a positive number. Press enter to end the program: ')
elif num < 0:
    reply = input('The number you typed is a negative number. Press enter to end the program: ')
elif num == 0:
    reply = input('The number 0 is neither a positive number nor a negative number. Press enter to end the program: ')
if reply == 'bye':
    input('Haha! So you got the easter egg! Ok bye! ;)')
