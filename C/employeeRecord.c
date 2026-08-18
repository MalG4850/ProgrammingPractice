#include <stdio.h>
#include <string.h>
struct Employee {
    int ID;
    char name[30];
    float salary;
};

int main(void) {
    int i = 0,n;
    printf("Enter the number of employees in the team: ");
    scanf("%d",&n);
    struct Employee team1[n];
    for (i=0;i<n;i++){
    //Employee 1
        printf("\n\nEnter the ID of Employee %d: ",i+1);
        if (scanf("%d",&team1[i].ID) != 1) {
            puts("Invalid Input!");
            return 0;
            }
    
        while (getchar() != '\n' && getchar() != EOF);
    
        printf("Enter the name of Employee %d: ",i+1);
        if (fgets(team1[i].name, sizeof(team1[i].name), stdin) == NULL) {
            puts("Invalid Input!");
            return 0;
            }
    
        printf("Enter the salary of Employee %d: ",i+1);
        if (scanf("%f",&team1[i].salary) != 1) {
            puts ("Invalid Input!");
            return 0;
            }
        }
        
    puts("\n\nThe employee data for this team is: \n\n");
    i = 0;
    for (i=0;i<n;i++) {
        printf("Employee %d: ",i+1);
        printf("\n\nID: %d",team1[i].ID);
        printf("\nName: %s",team1[i].name);
        printf("\nSalary: %.2f",team1[i].salary);
        puts("\n\n");
        }
    
    return 0;
}