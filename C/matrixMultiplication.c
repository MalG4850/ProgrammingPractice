#include <stdio.h>

int main(void) {
	int mat1[3][3],mat2[3][3],mat3[3][3],i = 0,j = 0,k = 0;
	
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
	
	//Initializing Matrix 3 as null matrix
	
	for (i = 0; i < 3; i++) {
    	for (j = 0; j < 3; j++) {
        mat3[i][j] = 0;
    	}
	}
	
	//Multiplying both matrices
	
	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			for (k = 0;k < 3;k++) {
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	
	//Displaying the multiplied matrix
	
	printf("\n\nThe final answer matrix is: \n\n");
	for (i = 0;i < 3;i++) {
		for (j = 0;j < 3;j++) {
			printf("%d	",mat3[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}