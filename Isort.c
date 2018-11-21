#include<stdio.h>
int InsSort(int a[],int size);
int main()
{
	int AR[500],N,i,co,x=0,n[100],it[100],k;
	printf("How many times do U want to run sorting?\n");
	scanf("%d",&co);
        for(k=0;k<co;k++)
 {
        printf("How many elements do U want to create array with?\n");
	scanf("%d",&N);
        n[k]=N;
	printf("\n Enter Array elements..\n");
	for(int i=0;i<N;i++)
		{
                    AR[i]=rand()%100;
                    printf("%d\n",AR[i]);
                    }

	x=InsSort(AR,N);
        it[k]=x;
	printf("\n\n The sorted array is as shown below..\n");
	for(i=0;i<N;i++)
	{printf("%d\n",AR[i]);}


 } 
printf("\n\tSize of arrays \tNo. of comparisons\n");         
 for(k=0;k<co;k++)
 { 
   printf("\t%d \t%d\n",n[k],it[k]);
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
int InsSort(int arr[], int n)
{
   int i, key, j,it=0;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
          it++;
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
return it;
}
