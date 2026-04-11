from time import sleep
list1 = []
list2 = []
teacher_name = input('Enter your name: ')
subject = input('Enter the subject you teach: ')
student_name = input("Enter your student's name: ")
subject_number = input('Enter the number of subjects of which you are going to type marks: ')
for i in range(1,subject_number + 1):
    element1 = input('Enter the name of the subjects of which you want to enter marks by separating them with commas: ')
    element2 = int(input('Enter the marks of each subject in the order you have mentioned by separating them with commas: '))
    list1.append(element1)
    list2.append(element2)
list1
list2
print('This is just to check that you have entered the correct marks for the correct subjects. \n Now, The average will be shown to you.')
average = 
print('Calculating......')
sleep(2)
print('Finalizing the output......')
sleep(3)
print('This is the final average: ',average)
