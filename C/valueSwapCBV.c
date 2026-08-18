#include <stdio.h>

int main(void) {
    int a,b;
    printf("Enter the value of the first number: a = ");
    scanf("%d",&a);
    printf("Enter the value of the second number: b = ");
    scanf("%d",&b);
    
    printf("Before swap: a = %d, b = %d\n", a, b);
    
    int temp = a;
    a = b;
    b = temp;
    
    printf("After swap, a = %d, b = %d.",a,b);
    
    return 0;
}
