list1 = []
number = int(input('Enter the number of elements you are going to enter: '))
for i in range(1,number + 1):
    element = int(input('Enter the elements you want to compare by separating them with commas. These will be stored in a list: \n'))
    list1.append(element)
print(min(list1))
