#include<iostream>
#include<math.h>
using namespace std;
class seq{
    public:
int a[100],n;
seq()
{
    cout<<"Enter n\n";
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
}
void sort()
{
    int tmp,ctr=0;
for(int i=0;i<n;i++)
	{
		for(int j=0;j<(n-1)-i;j++)
		{
			if(a[j]>a[j+1])
			{
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			 }
		   }
		   cout<<"Array after iteration-"<<++ctr<<"-is:";
		   for(int k=0;k<n;k++)
		   cout<<a[k]<<" ";
		   cout<<endl;
		 }

}
int MCSSS(int beg, int end)
{
    if(beg==end){
        if(a[beg]<0)
        return 0;
        else
        return a[beg];
    }
    int mid=(beg+end)/2;
    int LS=MCSSS(beg,mid);
    int RS=MCSSS(mid+1,end);
    int rosum=0,losum=0,rsum=0,lsum=0,msum=0;
    for(int i=mid;i<n;i++)
    {
        rsum+=a[i];
        if(rsum>rosum)
        rosum=rsum;
    }
    for(int i=mid-1;i<beg;i++)
    {
        lsum+=a[i];
        if(lsum>losum)
        losum=lsum;
    }
    msum=losum+rosum;
    int mx1=max(msum,LS);
    return(max(mx1,RS));
}
};
int main()
{
    seq s1;
    int x;
    s1.sort();
    x=s1.MCSSS(s1.a[0],s1.a[s1.n]);
    cout<<x;

}
