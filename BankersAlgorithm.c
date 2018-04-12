                                  //Bankers Algorithm//
    
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int Available[20][20];
	int Max[20][20];
	int Allocation[20][20];
	int Need[20][20];
	int p,r,choice,pno;
	int retvalue;
	printf("~~~~~~~~~~~~~~ BANKERS ALOGORITHM ~~~~~~~~~~~~~\n");
	intputvalue(Allocation,Need,Max,Available,&p,&r);
	retvalue=banker(Allocation,Available,Need,p,r);
	if(retvalue!=0)
	{
		printf("Do you want to make additional request ? (1=Yes||0=No)\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter process no. : ");
			scanf("%d",&pno);
			resource_request(Allocation,Need,Available,pno-1,r);
			retvalue=banker(Allocation,Available,Need,p,r);
			if(retvalue==0)
			 exit(0);
	    }
	}
	else
	 exit(0);
	 return 0;
	 
}
//Banker's Algorithm
void inputvalue(int Allocation[][20],int Need[][20],int Max[20][20],int Available[1][20],int *p,int *r)
{
	int i,j;
	printf("Enter the total no. of Processes : ");
	scanf("%d",p);
	printf("Enter the total no. of Resources : ");
	scanf("%d",r);
	for(i=0;i<*p;i++)
	{
		printf("\n Process P%d\n",i+1);
		for(j=0;j<*r;j++)
		{
			printf("Allocation of Resource %d : ",j+1);
			scanf("%d",&Allocation[i][j]);
			printf("Maximum for Resource %d : ",j+1);
			scanf("%d",&Max[i][j]);
		}
	}
	printf("\nAvailable Reasources : \n");
	for(i=0;i<*r;i++)
	{
		printf("Resource %d",i+1);
		scanf("%d",&Available[0][i]);
	}
	
	for(i=0;i<*p;i++)
	for(j=0;j<*r;j++)
	Need[i][j]=Max[i][j]-Allocation[i][j];
		
	printf("\n Allocation Matrix");
	print(Allocation,*p,*r);
	printf("\n Maximum Requirement Matrix");
	print(Max,*p,*r);
	printf("\n Need Matrix");
	print(Need,*p,*r);
}

