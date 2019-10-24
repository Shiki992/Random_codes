#include<iostream>
#include<limits.h>
#include<math.h>
using namespace std;
int AR[100],AR2[100],AR3[100];
int InsSort(int AR[],int size)   //function to perform Insertion Sort
{
	int tmp,j,i,cnt=0;
	//AR[0]=INT_MIN;
	for(int i=1;i<=size;i++)
	{
		tmp=AR[i];
		j=i-1;
		while(tmp<AR[j])
	    {
            cnt++;
			AR[j+1]=AR[j];
			j--;
		}
	   AR[j+1]=tmp;
	   cout<<"Array after pass-"<<i<<"-is:";
	   for(int k=0;k<size;k++)
	   cout<<AR[k]<<" ";
	   cout<<endl;
	}
    return cnt;
}
int BubbleSort(int AR[],int size)
{
    int tmp,ctr=0,i,j,k;
	for(i=0;i<size;i++)
	{
		for(j=0;j<(size-1)-i;j++)
		{
			if(AR[j]>AR[j+1])
			{
                //ctr++;
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
return ctr;
}

int SelSort (int AR[],int size)
{
int small, pos, tmp,i,j,cnt=0;
for (int i = 0; i<size - 1; i++)
{
small = AR[i];
pos = i;
for(j = i+1; j<size; j++)
{
if (AR[j]<small)
{
cnt++;
small = AR[j];
pos = j;
}

}
tmp = AR[i];
AR[i] = AR[pos];
AR[pos] = tmp;
cout <<"\n Array after pass"<<i+1<<"is: ";
for (j = 0; j<size; j++)
cout<<AR[j]<<" ";
}
    return cnt;
}


void Entervalues(int size)
{
    int i;
//cout<<"\n Enter Array elements..\n";
for(i=0;i<size;i++)
//cin>>AR[i];
AR[i]=AR2[i]=AR3[i]=rand()%100;

}


void Printvalues(int AR[],int size)
{
    int i;
    cout<<"\n\n The array is as shown below..\n";
	for(i=0;i<size;i++)
	cout<<AR[i]<<" ";
	cout<<endl;
}
int AVGCalc(int A[],int size)
{
    int i,avg,sum=0;
    for(i=0;i<size;i++)
    {
        sum+=A[i];
    }
    avg=sum/size;
    return avg;
}
int main()
{
    int I[5],B[5],S[5],i,ai,as,ab;
    for(i=0;i<5;i++)
    {
    Entervalues(20);
    Printvalues(AR,20);
    I[i]=InsSort(AR,20);
    Printvalues(AR,20);
    B[i]=BubbleSort(AR2,20);
    Printvalues(AR2,20);
    S[i]=SelSort(AR3,20);
    Printvalues(AR3,20);
    }
    Printvalues(I,5);
    Printvalues(B,5);
    Printvalues(S,5);
    ai=AVGCalc(I,5);
    ab=AVGCalc(B,5);
    as=AVGCalc(S,5);
    cout<<"The avg of Insertion="<<ai<<endl;
    cout<<"The avg of Bubble="<<ab<<endl;
    cout<<"The avg of Selection="<<as<<endl;
    return 0;
}