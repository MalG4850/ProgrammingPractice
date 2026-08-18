#include <stdio.h>

int main(void) {
	int sum = 0,i = 0,lastDigit,n,num;
	printf("This is a program which calculates the sum of digits of a given number.");
	
	//Getting number from user
	printf("\n\nEnter a number: ");
	scanf("%d",&num);
	
	n = num;
	
	//Logic
	while (n != 0) {
		lastDigit = n % 10;
		sum += lastDigit;
		n /= 10;
	}
	
	printf("The sum of digits of %d is %d.",num,sum);
	return 0;
}