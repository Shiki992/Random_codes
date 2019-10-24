#include<iostream.h>
#include<conio.h>
#include<limits.h>                //for INT_MIN
void InsSort(int [],int);	//function for insertion sort
void main()
{
	int AR[50],ITEM,N,index;	//array can hold max.50 elements
	clrscr();
	cout<<"How many elements do U want to create array with?(max.50)..";
	cin>>N;
	cout<<"\n Enter Array elements..\n";
	for(int i=1;i<=N;i++)
		cin>>AR[i];
	InsSort(AR,N);
	cout<<"\n\n The sorted array is as shown below..\n";
	for(i=1;i<=N;i++)
	cout<<AR[i]<<" ";
	cout<<endl;
	getch();
}
void InsSort(int AR[],int size)   //functionto perform Bubble Sort
{
	int tmp,j;
	AR[0]=INT_MIN;
	for(int i=1;i<=size;i++)
	{
				tmp=AR[i];
				j=i-1;
				while(tmp<AR[j])
				{
					AR[j+1]=AR[j];
					j--;
				}
		   AR[j+1]=tmp;
		   cout<<"Array after pass-"<<i<<"-is:";
		   for(int k=1;k<=size;k++)
		   cout<<AR[k]<<" ";
		   cout<<endl;
		 }
	   }