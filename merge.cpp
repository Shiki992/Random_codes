#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class word
{
public:
string word;
string mean;
void read();
};
class so
{
 public:
 word w[100];
 word sa[100];
 void sor(int beg,int end);
 void merge(int beg,int end);
 int find(int las);
 void place(int pos,int las);
};
int so :: find(int las)
{
 for(int i=0;i<las;i++)
 {
  if(w[i].word>w[las].word)
  {
   return i;
  }
 }
 return las;
}
void so :: place(int pos,int las)
{
 if(pos==las)
  return;
 else
 {
  string temp3=w[pos].word,temp4=w[pos].mean,temp5,temp6;
  for(int i=pos;i<las;i++)
  {
   temp5=w[i+1].word;
   temp6=w[i+1].mean;
   w[i+1].word=temp3;
   w[i+1].mean=temp4;
   temp3=temp5;
   temp4=temp6;
  }
  w[pos].word=temp3;
  w[pos].mean=temp4;
 }
}
   
void so :: sor(int beg,int end)
{
int mid;
if(beg<end)
{
mid=(beg+end)/2;
sor(beg,mid);
sor(mid+1,end);
merge(beg,end);
}
}

void so :: merge(int beg,int end)
{
 int mid=(beg+end)/2,i=beg,j=mid+1,k=0;
 while((i<=mid)&&(j<=end))
 {
  if(w[i].word<w[j].word)
  {
   sa[k].word=w[i].word;
   sa[k].mean=w[i].mean;
   i++;
   k++;
  }
  else
  {
   sa[k].word=w[j].word;
   sa[k].mean=w[j].mean;
   j++;
   k++;
  }
 }
 if(i<=mid)
 {
  for(;i<=mid;i++)
  {
   sa[k].word=w[i].word;
   sa[k].mean=w[i].mean;
   k++;
  }   
 }
 if(j<=end)
 {
  for(;j<=end;j++)
  {
   sa[k].word=w[j].word;
   sa[k].mean=w[j].mean;
   k++;
  }   
 }
 for(int h=0;h<=(end-beg);h++)
 {
  w[beg+h].word=sa[h].word;
  w[beg+h].mean=sa[h].mean;
 }
}

void word :: read()
{
 cout<<"enter word\n";
 cin>>word;
 cout<<"enter meaning\n";
 cin>>mean;
}

int main()
{
 so b;
 int n,temp=1,ch,m,k;
 cout<<"number of words\n";
 cin>>n;
 for(int t=0;t<n;t++)
 {
  b.w[t].read();
 }
/* for(int t=0;t<n;t++)
 {
  cout<<b.w[t].word<<" ";
 } */
 b.sor(0,n-1);
 cout<<"sorted dictionary is\n";
 for(int t=0;t<n;t++)
 {
  cout<<b.w[t].word<<" "<<b.w[t].mean<<"\n";
 }
 while(temp)
 {
  cout<<"enter your choice\n";
  cout<<"1.enter a word\n";
  cout<<"2.quit\n";
  cin>>ch;
  switch(ch)
  {
   case 1:
    b.w[n].read();
    n++;
    k=b.find(n-1);
    cout<<k;
    b.place(k,n-1);
    cout<<"the dictionary is\n";
    for(int t=0;t<n;t++)
    {
      cout<<b.w[t].word<<" "<<b.w[t].mean<<"\n";
    }
   break;
   case 2:
    temp=0;
   break;
   default:
    cout<<"worng choice";
  }
 }
 return 0;
}
