from time import sleep
num = int(input('Enter a number: '))
mod = num %2
if mod == 0:
    sleep(0.5)
    input('This number is an even number. Press enter to exit the program: ')

else:
    sleep(0.5)
    input('This number is an odd number. Press enter to exit this program: ')
