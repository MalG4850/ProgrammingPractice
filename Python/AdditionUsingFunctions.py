from time import sleep
def Addition():
    x = int(input('This is a simple addition program with which you add 2 numbers. Type your first number: '))
    y = int(input('Okay. Now type in the second number you want to add: '))
    print('Adding........')
    sleep(3)
    reply = input('Do you want to see the result? ')
    if(reply == 'yes' or 'Yes' or 'y' or 'Y' or 'yeah' or 'Yeah'):
        print('Here is the result: ' + str(x + y))
        input('Press enter to exit the program: ')
    elif(reply == 'no' or 'No' or 'n' or 'N' or 'nada' or 'Nada'):
        print('Okay. Your choice. \n')
        input('Press enter to exit the program: ')

Addition()
print('now there is a subtraction program. \n')
from time import sleep
def Subtraction():
    x = int(input('This is a simple subtraction program with which you subtract 2 numbers. Type your first number: '))
    y = int(input('Okay. Now type in the second number you want to subtract from the first number: '))
    print('Subtracting........')
    sleep(3)
    reply = input('Do you want to see the result? ')
    if(reply == 'yes' or 'Yes' or 'y' or 'Y' or 'yeah' or 'Yeah'):
        print('Here is the result: ' + str(x - y))
        input('Press enter to exit the program: ')
    elif(reply == 'no' or 'No' or 'n' or 'N' or 'nada' or 'Nada'):
        print('Okay. Your choice. \n')
        input('Press enter to exit the program: ')

Subtraction()
print('')
