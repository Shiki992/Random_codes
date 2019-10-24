#include<iostream.h>
#include<conio.h>
void BubbleSort(int [],int);	//function for bubble sort
void main()
{
	int AR[50],ITEM,N,index;	//array can hold max.50 elements
	clrscr();
	cout<<"How many elements do U want to create array with?(max.50)..";
	cin>>N;
	cout<<"\n Enter Array elements..\n";
	for(int i=0;i<N;i++)
		cin>>AR[i];
	BubbleSort(AR,N);
	cout<<"\n\n The sortedarray is as shown below..\n";
	for(i=0;i<N;i++)
	cout<<AR[i]<<" ";
	cout<<endl;
	getch();
}
void BubbleSort(int AR[],int size)   //functionto perform Bubble Sort
{
	int tmp,ctr=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<(size-1)-i;j++)
		{
			if(AR[j]>AR[j+1])
			{
				tmp=AR[j];
				AR[j]=AR[j+1];
				AR[j+1]=tmp;
			 }
		   }
		   cout<<"Arrayafteriteration-"<<++ctr<<"-is:";
		   for(int k=0;k<size;k++)
		   cout<<AR[k]<<" ";
		   cout<<endl;
		 }
	   }