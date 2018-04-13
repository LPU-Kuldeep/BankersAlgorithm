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
int banker(int Allocation[][20],int Need[][20],int Available[1][20],int p,int r)
{
	int j,i,arr[20];
	j=safetyAlgorithm(Allocation,Need,Available,p,r,arr);
	if(j!=0)
	{
		printf("\n\n");
		for(i=0;i<p;i++)
		printf("P%d",arr[i]);
		printf("Safety Sequence has been detected.\n");
		return 1;
	}
	else
	{
		printf("Deadlock has occured.\n");
		return 0;
	}
}
// Safety Algorithm
int safety(int Allocation[][20],int Need[][20],int AV[1][20],int p,int r,int arr[])
{
	int i,j,k,x=0;
	int F[10],Available[1][20];
	int pflag=0,flag=0;
	for(i=0;i<p;i++)
		F[i]=0;
	for(i=0;i<r;i++)
		Available[0][i]=AV[0][i];
	for(k=0;k<p;k++)
	{
		for(i=0;i<p;i++)
		{
			if(F[i]==0)
			{
				flag=0;
				for(j=0;j<r;j++)
				{
					if(Need[i][j]>Available[0][j])
						flag=1;
				}
				if(flag==0 && F[i]==0)
				{
					for(j=0;j<r;j++)
						Available[0][j]+=Allocation[i][j];
					F[i]=1;
					pflag++;
					arr[x++]=i;
				}
			}
		}
		if(pflag==p)
			return 1;
	}
	return 0;
}

		
