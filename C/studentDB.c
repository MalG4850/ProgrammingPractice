#include <stdio.h>

struct Student {
    char firstName[20];
    char lastName[30];
    int rollNumber;
    float studentMarks;
};
int main(void) {
    int i = 0,n;
    
    printf("Enter the number of students in the assigned batch: ");
    scanf("%d",&n);
    
    struct Student s1[n];
    
    for (i = 0;i < n;i++) {
    	printf("Enter the first name of the student: ");
    	scanf("%s",&s1[i].firstName);
    	
    	printf("Enter the last name of the student: ");
    	scanf("%s",&s1[i].lastName);

    	printf("\nEnter the PRN/Roll Number of the student: ");
    	if (scanf("%d",&s1[i].rollNumber) != 1){
        	puts("Invalid Input!");
        	return 0;
    	}
    
    	printf("\n\nEnter the CGPA of the student: ");
    	if(scanf("%f",&s1[i].studentMarks) != 1){
        	puts("Invalid Input!");
        	return 0;
    	}
	}
	
	for (i = 0;i < n;i++){
    	printf("\n\n\n");
    	printf("The details of the given student are: ");
    	printf("\n\n1. Name: %s %s\n\n2. PRN/Roll Number: %d\n\n3. CGPA: %.2f",s1[i].firstName,s1[i].lastName,s1[i].rollNumber,s1[i].studentMarks);
	}
	return 0;
}