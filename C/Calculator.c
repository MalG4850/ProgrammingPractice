#include <stdio.h>
int main(void){
    int choice,a,b,ans;
    printf("This is a program to do arithmetic operations on 2 numbers.");
    
    printf("Which operation do you want to do?\n\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n\nEnter your choice: ");
    scanf("%d",&choice);
    
    printf("\nEnter the first number: ");
    scanf("%d",&a);
    printf("\nEnter the second number: ");
    scanf("%d",&b);

    switch (choice) {
        case 1:
            ans = a + b;
            break;
    
        case 2: 
            ans = a - b;
            break;
            
        case 3: 
            ans = a * b;
            break;

        case 4: 
            ans = a/b;
            break;
    }

    printf("The answer is: %d",ans);
    
    return 0;
}