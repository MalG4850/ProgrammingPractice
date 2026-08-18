#include <stdio.h>

int main(void) {
	int mat1[3][3],mat2[3][3],mat3[3][3],i = 0,j = 0;
	printf("This is a program to do 3x3 Matrix addition.");
	printf("\nElements will be accepted row-wise.\n");
	
	//Accepting Matrix 1
	
	printf("\nAccepting Matrix 1.\n\n");
	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			printf("\nEnter the element: ");
			scanf("%d",&mat1[i][j]);
		}
	}
	
	//Displaying Matrix 1
	
	printf("\nThe following is the recorded 1st 3x3 Matrix: \n\n");
	for (i = 0;i<3;i++) {
		for (j = 0;j < 3;j++) {
			printf("%d	",mat1[i][j]);
		}
		printf("\n");
	}
	
	//Accepting Matrix 2
	
	printf("\n\nAccepting Matrix 2.\n\n");
	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			printf("\n\nEnter the element: ");
			scanf("%d",&mat2[i][j]);
		}
	}
	
	//Displaying Matrix 2
	
	printf("\nThe following is the recorded 2nd 3x3 Matrix: \n\n");
	for (i = 0;i<3;i++) {
		for (j = 0;j < 3;j++) {
			printf("%d	",mat2[i][j]);
		}
		printf("\n");
	}
	
	//Adding both matrices
	
	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++){
			mat3[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	
	//Displaying the added matrix
	
	printf("\n\nThe final answer matrix is: \n\n");
	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			printf("%d	",mat3[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}