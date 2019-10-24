#include<iostream.h>
#include<conio.h>
int Lsearch(int[],int,int);   //i.e.,Lsearch(the array,its size,search_item)
int main()
{
	int AR[50],ITEM,N,index;
	cout<<"Enter desired arraysize(max.50)...";
	cin>>N;
	cout<<"\nEnter Array elements\n";
	for(int i=0;i<N;i++)
	{
		cin>>AR[i];
	}
	cout<<"\nEnter Element to be searched for..";
	cin>>ITEM;
	index=Lsearch(AR,N,ITEM);
	if(index==-1)
		cout<<"\nSorry!!Given element could not be found.\n";
	else
		cout<<"\nElement found at index:"<<index<<",Position:"<<index+1<<endl;
		return 0;
}
int Lsearch(int AR[],int size,int item)  //function to perform linear search
{
	for(int i=0;i<size;i++)
	{
		if(AR[i]==item)
		return i;		//return index of otem in case of successful search
	}
	return -1;	//the control will reach here only when the item is not found
}

