from time import sleep
num = (1,2,3,4,5,6,7,8,9)
odd_count = 0
even_count = 0
for i in num:
    if i % 2 == 0:
        even_count += 1
    else:
        odd_count += 1
input('Press enter to reveal even and odd numbers: ')
print('Revealing.......')
sleep(2)
print('Even Numbers: ' + str(even_count) + ' ')
print('Odd Numbers: ' + str(odd_count) + ' ')
input('Press enter to exit this program: ')
