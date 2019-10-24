#include<iostream>
#include<limits.h>                //for INT_MIN

using namespace std;

void InsSort(int size);	//function for insertion sort
void BubbleSort(int size); //function for Bubble sort
void SelSort(int size);  //function for Selection sort
int main()
{
	int i,AR[50],ITEM,N,index=0;	//array can hold max.50 elements
	cout<<"How many elements do U want to create array with?(max.50)..";
	cin>>N;
	while(index==0)
    {
	cout<<"Name the Sort"<<endl<<"1)Insertion"<<endl<<"2)Bubble"<<endl<<"3)Selection"<<endl<<"4)EXIT"<<endl;
	cin>>ITEM;
	switch(ITEM)
	{
	    case 1:InsSort(N);
                break;
        case 2:BubbleSort(N);
                break;
        case 3:SelSort(N);
                break;
        case 4:index=1;
                break;
        default:cout<<"INVALID RESPONSE!!! TRY AGAIN!!"<<endl;
                break;
	}
    }
	return 0;
}
void InsSort(int size)   //functionto perform Bubble Sort
{
	int AR[100],tmp,j,i;
	cout<<"\n Enter Array elements..\n";
for(i=1;i<=size;i++)
		cin>>AR[i];
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
		 cout<<"\n\n The sorted array is as shown below..\n";
	for(i=1;i<=size;i++)
	cout<<AR[i]<<" ";
	cout<<endl;
	   }
void BubbleSort(int size)
{
    int AR[100],tmp,ctr=0,i,j,k;
    cout<<"\n Enter Array elements..\n";
	for(i=0;i<size;i++)
		cin>>AR[i];
	for(i=0;i<size;i++)
	{
		for(j=0;j<(size-1)-i;j++)
		{
			if(AR[j]>AR[j+1])
			{
				tmp=AR[j];
				AR[j]=AR[j+1];
				AR[j+1]=tmp;
			 }
		   }
		   cout<<"Array after iteration-"<<++ctr<<"-is:";
		   for(k=0;k<size;k++)
		   cout<<AR[k]<<" ";
		   cout<<endl;
		 }
		 cout<<"\n\n The sorted array is as shown below..\n";
	for(i=0;i<size;i++)
	cout<<AR[i]<<" ";
	cout<<endl;
}

void SelSort (int size)
{
int AR[100],small, pos, tmp,i,j;
cout<<"\n Enter Array elements..\n";
for(i=0;i<size;i++)
cin>>AR[i];
for (int i = 0; i<size - 1; i++)
{
small = AR[i];
pos = i;
for(j = i+1; j<size; j++)
{
if (AR[j]<small)
{
               small = AR[j];
pos = j;
}
}
tmp = AR[i];
AR[i] = AR[pos];
AR[pos] = tmp;
cout <<"\n Array after pass"<<i+1<<"is: ";
for (j = 0; j<size; j++)
cout<<AR[j]<<'\t';
}
    cout<<"\n\n The sorted array is as shown below..\n";
	for(i=0;i<size;i++)
	cout<<AR[i]<<" ";
	cout<<endl;
}
