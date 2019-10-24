#include<iostream.h>
#include<conio.h>
int Bsearch(int[],int,int);      //i.e.,Bsearch(the array,its size,search_item)
int main()
{
	clrscr();
	int AR[50],ITEM,N,index;     //array can hold max.50 elements
	cout<<"Enter desired array size(max.50)...";
	cin>>N;
	cout<<"\nEnter Array elements(must besorted in Asc order)\n";
	for(int i=0;i<N;i++)
	cin>>AR[i];
	cout<<"\nEnter Element to be searched for...";
	cin>>ITEM;
	index=Bsearch(AR,N,ITEM);
	if(index==-1)
		cout<<"\nSorry!!Given element could not be found.\n";
	else
		cout<<"\nElement found at index:"<<index<<",Position:"<<index+1<<endl;
		return 0;
}
int Bsearch(int AR[],int size,int item)    //function to perform binary search
{
	int beg,last,mid;
	beg=0;
	last=size-1;
	while(beg<=last)
	{
		mid=(beg+last)/2;
		if(item==AR[mid])
			return mid;
		else if(item>AR[mid])
			beg=mid+1;
		else
			last=mid-1;
	 }
	 return -1;         //the control will reach here only only when item is not found
}

