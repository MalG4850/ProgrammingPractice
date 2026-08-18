#include <stdio.h>
int main(void){
    int num;
    printf("This is a code to check if the given number is odd or even.");
    printf("\nEnter a number to check: ");
    scanf("%d",&num);
    
    if (num % 2 == 0)
        printf("%d is an even number.",num);
        
    else
        printf("%d is an odd number.",num);
    return 0;
}