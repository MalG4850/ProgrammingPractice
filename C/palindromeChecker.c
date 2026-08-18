#include <stdio.h>
#include <string.h>

int main(void) {
    char str[50];
    int checker = 0,i=0;

	//Input from user
	
    printf("Enter a string to check if it is a palindrome or not: ");
    if(scanf("%s",&str) != 1) {
        puts("Invalid Input!");
        return 0;
    }
    int len = strlen(str);
    
    //Logic
    
    for (i = 0;i<len/2;i++) {
    
        if(str[i] != str[len - i - 1]) {
            checker = 1;
            break;
        }
        
    }
    
    //Output
    
    if(checker == 0) {
        printf("%s is a palindrome.",str);
    } else {
        printf("%s is not a palindrome.",str);
    }
    return 0;
}