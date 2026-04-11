list1 = []
x = int(input('Type the number of elements you are going to type: '))
for n in range(1,x + 1):
    elements = int(input('Type in the element: '))
    list1.append(elements)
    print(' ')
for y in list1:
    if y % 2 != 0:
            print(y,end = ' ')
