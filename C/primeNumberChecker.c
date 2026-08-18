#include <stdio.h>

int main(void) {
    int n, i, checker = 1;

	//Getting number from user
	
    printf("Enter a positive integer: ");
    scanf("%d", &n);

	//Logic
	
    if (n <= 1) {
        checker = 0;
        
    } else {
        
        for (i = 2; i * i <= n; i++) {
            
            if (n % i == 0) {
                
                checker = 0;
                break;
            }
        }
    }

	//Output
	
    if (checker)
        printf("%d is a prime number.\n", n);
    
    else 
        printf("%d is not a prime number.\n", n);

    return 0;
}
