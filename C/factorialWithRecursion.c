#include <stdio.h>

int factorial (int n) {
	if (n > 0) {
		return n * factorial(n-1);
	}
	else if (n == 0)
		return 1;
	else
		printf("Factorial of Negative numbers is not defined.");
	return 0;
}

int main(void) {
	int n = 0,fact;
	
	input:
		printf("Enter the number for its Factorial: ");
	
	scanf("%d",&n);
		
		fact = factorial(n);
		printf("The factorial of %d is %d.",n,fact);
	
	return 0;
}