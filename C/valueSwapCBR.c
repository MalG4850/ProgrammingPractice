#include <stdio.h>

void swapValues(int*a,int*b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x,y;
    int*a = &x;
    int*b = &y;
    
    printf("This is a program to swap the values of 2 numbers using pointers.\n\n");
    
    input1:
        printf("Enter the first number: x = ");
        
    if (scanf("%d",a) != 1){
        printf("Invalid Input! Kindly re-run the program.\n");
        return 0;
    }
    
    input2:
        printf("\nEnter the value of the second number: y = ");
        
    if(scanf("%d",b) != 1){
        printf("Invalid Input! Kindly re-run the program.\n");
        return 0;
    }
    
    swapValues(a,b);
    printf("\nThe swapped values are: x = %d and y = %d.",*a,*b);
    
    return 0;
}