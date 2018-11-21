#include<stdio.h>
int BubbleSort(int AR[],int size);
int main()
{
	int AR[500],ITEM,N[500],index,i,count[100],k=0,counter,num=0,den=0;
float wavg=0.000000;
printf("How many times do you want to run the sort?\n");
scanf("%d",&index);
for(k=0;k<index;k++)
{
	printf("How many elements do U want to create array with?..");
	scanf("%d",&N[k]);
          ITEM=N[k];
	printf("\n Entered Array elements..\n");
	for(i=0;i<N[k];i++)
	{
           AR[i]=rand()%100;
           printf("%d\n",AR[i]);
          }
	counter=BubbleSort(AR,ITEM);
          count[k]=counter;
	printf("\n\n The sorted array is as shown below..\n");
	for(i=0;i<N[k];i++)
	printf("%d\n",AR[i]);
}
printf("Size of array \tNo. of Comparisons\n");
for(k=0;k<index;k++)
{
printf("\n\t%d \t\t%d\n",N[k],count[k]);
}
printf("Hence, Weighted average=  ");
for(k=0;k<index;k++)
{
num+=(N[k]*count[k]);
den+=N[k];
}
wavg=num/den;
printf("%f\n",wavg);

	return(0);
}
int BubbleSort(int AR[],int size)
{
	int i,tmp,ctr=0;
	for( i=0;i<size;i++)
	{
		for(int j=0;j<(size-1)-i;j++)
		{
			if(AR[j]>AR[j+1])
			{
				tmp=AR[j];
				AR[j]=AR[j+1];
				AR[j+1]=tmp;
			 }
			 ctr++;
		   }



		 }

	printf("Total no of comparisons are: %d ",ctr);
return ctr;	   
}
