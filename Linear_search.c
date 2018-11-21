#include<stdio.h>
void main()
{
int a[500],x,n,i;
printf("enter no. of inputs ");
scanf("%d",&n);


for( i=0;i<n;i++)
{
    a[i] = rand();
     printf("%d\n", a[i]);
}
printf("enter the no. u want to search for");
scanf("%d", &x);
for(int i=0;i<n;i++)
{
    if(x==a[i])
    {
        printf("the no. %d is found at %d th position\n",x,i+1);
        printf("no. of comparisons= %d",i+1);
    }
}


return 0;
}
