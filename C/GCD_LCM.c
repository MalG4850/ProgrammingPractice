#include <stdio.h>
#include <stdlib.h>


//GCD Logic

int gcd(int a, int b) {
	int i = 1,gcd = 1;
	for (i = 1;i <= a && i <= b;i++) {
		if (a % i == 0 && b % i == 0) {
			gcd = i;
		}
	}
	return gcd;
}


//LCM Logic

int lcm(int a, int b) {
	int lcm = 1;
	lcm = abs(a*b)/gcd(a,b);
	return lcm;
}

int main(void) {
	int a,b,choice,i = 0,gcdVal,lcmVal;
	printf("This is a program to calculate the GCD or LCM of given 2 numbers.\n");
	
	//User input
	
	printf("\nEnter the first number: ");
	scanf("%d",&a);
	
	printf("\nEnter the second number: ");
	scanf("%d",&b);
	
	printf("Which output do you want of the 2 numbers?\n\n1. GCD\n2. LCM\n\nEnter your choice: ");
	scanf("%d",&choice);
	
	if (choice == 1) {
		gcdVal = gcd(a,b);
		printf("The GCD of %d and %d is %d.\n\n\n",a,b,gcdVal);
	}
	
	else if (choice == 2) {
		lcmVal = lcm(a,b);
		printf("The LCM of %d and %d is %d.\n\n\n",a,b,lcmVal);
	}
	
	return 0;
}