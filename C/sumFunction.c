#include <stdio.h>

int sum(int a,int b) {
    int s = a + b;
    return s;
}

int main(void) {
    int a,b;
    printf("This is a program for the addition of 2 numbers.");
    printf("\nEnter the first number: a = ");
    scanf("%d",&a);
    printf("\nEnter the value of the second number: b = ");
    scanf("%d",&b);
    int s = sum(a,b);
    printf("The sum of the %d and %d is %d.",a,b,s);
    
    return 0;
}