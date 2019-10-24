#include<stdio.h>
int fibonacci(int n);
int count;
void main()
{
int n;
printf("enter the no. of fibonacci nos. u want\n");
scanf("%d",&n);
fibonacci(n);
printf("%d",count);
return 0;

}
 int fibonacci(int a)
 {
 long int f[1000],count=0;
 f[0]=0;
 f[1]=1;
 printf("%d\n%d\n",f[0],f[1]); 
 for(int i=2;i<a;i++)
 {
 f[i]=f[i-1]+f[i-2];
 printf("%d\n",f[i]);
 count++;
 }
 return count;
 }
 //mean,median mode,
 //n factorial
 //find gradient of n integers in an arrray
 //find value of epower x given x
 
