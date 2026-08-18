#include<stdio.h>
int main() 
{
	int array[]={10,20,30,40,50};
	int n=5,x=1;
	int ch , j , i , position , value;
	
	while(x=1)
	{
		printf("\n------MENU------\n");
		printf("\n1.Display\n");
		printf("\n2.Insert\n");
		printf("\n3.Delete\n");
		printf("\n4.Exit\n");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:
			printf("The Original Array is : \n");
			for(i=0;i<n;i++)
			printf("%d ",array[i]);
			break;
	
			case 2: //Insertion
			printf("Please enter the Position of the element 1- %d : ",n);
			scanf("%d",&position);
			printf("\nPlease enter the Value : ");
			scanf("%d",&value);
			for(i=0;i<n;i++)
			{
			    if(i==position-1)
			    {
				    array[i]=value;
			    }
			}
			printf("Insertion Completed!\n");
			printf("The array is: ");
			for(i=0;i<=4;i++){
			printf("%d ",array[i]);
			}
			break;
			
			case 3: //Deletion
			    break;
			case 4:
			    return 0;
		}		
	}
return 0;
}
