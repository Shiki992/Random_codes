#include<stdio.h>
int main()
{
    int i,j,n,N[100],loc,temp,min,a[300],k,index,ctr[100],count=0,num=0,den=0;
float wavg=0.000000;
printf("How many times do you want to run the sort?\n");
scanf("%d",&index);
          for(k=0;k<index;k++)
{
    printf("Enter the number of elements:");
    scanf("%d",&N[k]);
n=N[k];
    printf("\nEntered elements\n");

    for(i=0;i<n;i++)
    {
	a[i]=rand()%100;
          printf("%d\n",a[i]);
    }

    for(i=0;i<n-1;i++)
    {
	min=a[i];
	loc=i;
	for(j=i+1;j<n;j++)
	{
count++;
	    if(min>a[j])
	    {
		min=a[j];
		loc=j;
	    }
	}

	temp=a[i];
	a[i]=a[loc];
	a[loc]=temp;
    }
ctr[k]=count;
count=0;
    printf("\nSorted list is as follows\n");
    for(i=0;i<n;i++)
    {
	printf("%d\n",a[i]);
    }

}
printf("Size of array \tNo. of Comparisons\n");
for(k=0;k<index;k++)
{
printf("\n\t%d \t\t%d\n",N[k],ctr[k]);
}
printf("Hence, Weighted average=  ");
for(k=0;k<index;k++)
{
num+=(N[k]*ctr[k]);
den+=N[k];
}
wavg=num/den;
printf("%f\n",wavg);
    return(0);

}
