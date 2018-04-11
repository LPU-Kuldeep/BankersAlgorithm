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
