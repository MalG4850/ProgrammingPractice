#include <stdio.h>
int main(void){
    int s1,s2,s3,s4,s5,avg;
    printf("This is a cumulative grade calculation tool for 5 subjects.\n");
    //Subject 1
    printf("\nEnter the marks of the first subject out of 100: ");
    scanf("%d",&s1);
    
    //Subject 2
    printf("\nEnter the marks of the second subject out of 100: ");
    scanf("%d",&s2);
    
    //Subject 3
    printf("\nEnter the marks of the third subject out of 100: ");
    scanf("%d",&s3);
    
    //Subject 4
    printf("\nEnter the marks of the fourth subject out of 100: ");
    scanf("%d",&s4);
    
    //Subject 5
    printf("\nEnter the marks of the fifth subject out of 100: ");
    scanf("%d",&s5);
    
    avg = (s1 + s2 + s3 + s4 + s5)/5;
    
    if (avg >=90)
        printf("\nCumulative Grade: A");
        
    else if (avg >=75 && avg < 90)
        printf("\nCumulative Grade: B");
        
    else if (avg >= 60 && avg < 75)
        printf("\nCumulative Grade: C");
        
    else if (avg >= 40 && avg < 60)
        printf("\nCumulative Grade: D");
        
    else if (avg < 40)
        printf("\nCumulative Grade: Fail");
    
    return 0;
}