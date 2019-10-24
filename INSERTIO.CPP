#include<iostream.h>
#include<conio.h>
#include<process.h>             //for exit()
int FindPos(int [],int,int);    //function to determine the right position for new element
int main()
{
	int AR[50],ITEM,N,index;   //array can hold max.50 elements
	cout<<"How many elements do you want to create array with?(max.50)...";
	cin>>N;
	cout<<"\nEnter Array elements(must be sorted in Asc Order)\n";
	for(int i=0;i<N;i++)
		cin>>AR[i];
	char ch='y';
	while(ch=='y'||ch=='y')
	{
		cout<<"\nEnter element to be inserted..";
		cin>>ITEM;
		if(N==50)
		{
			cout<<"Overflow!!\n";
			exit(1);
		}
		index=FindPos(AR,N,ITEM);
		for(i=N;i>index;i--)
		{
			AR[i]=AR[i-1];     //Shift elements to create room for new element
		}
		AR[index]=ITEM;            //item inserted
		N+=1;			  //Number of elements updated
		cout<<"\n Want to insert more elements?(y/n)...";
		cin>>ch;
	 }
	 cout<<"The array now is as shown below..\n";
	 for(i=0;i<N;i++)
		cout<<AR[i]<<" ";
		cout<<endl;
		return 0;
}
int FindPos(int AR[],int size,int item)     //function to determine the position for new element
{
	int pos;
	if(item<AR[0])
		pos=0;
	else
	{
		for(int i=0;i<size-1;i++)
		{
			if(AR[i]<=item&&item<AR[i+1])
			{
				pos=i+1;
				break;
			}
		 }
		 if(i==size-1)
		 pos=size;
	 }
	 return pos;
}
