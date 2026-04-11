n = int(input('Enter the number of terms you want to see in the Fibonacci Sequence: '))
n1 = 0
n2 = 1
count = 1
sum = 0
while count <= n:
    print(sum,end = ' ')
    count += 1
    n1 = n2
    n2 = sum
    sum = n1 + n2

