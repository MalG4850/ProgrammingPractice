#include <stdio.h>
int main(void){
    int year;
    printf("This is a code to check if the given year is leap or not.");
    printf("\nEnter the year to check: ");
    scanf("%d",&year);
    
    if (year % 4 == 0)
        printf("%d is a leap year.",year);
        
    else
        printf("%d is not a leap year.",year);
    return 0;
}