#include <stdio.h>

int main(void) {
    int n, i;
    unsigned long long fact = 1;

    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } 
    else {
        for (i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %llu\n", n, fact);
    }

    return 0;
}