#include<stdio.h>
struct list
{
    int arr[500],lsize;

};
void insertion(struct list *pl,int pos,int x);
int deletion(struct list *pl,int pos);
int search(struct list *pl, int x);
int isempty(struct list l);
int isfull(struct list l);

void main()
{
    struct list L1;
    L1.lsize=0;
    int i,s,n,n1;
    int m=1;
char str;  
    while(m==1)
{
    printf("Enter the position at which you want to insert the element and element\n");
    scanf("%d",&i);
    if(i>=L1.lsize+1)
    {
          printf("not applicable\n");
          
          break;
    }
    else if(scanf("%d%c",&s,&str)!=2|| str!='\n')
    {
          printf("not applicable\n");
          
          break;
    }
    else
    {
    insertion(&L1,i,s);
    printf("do you want to insert more elements?(1/0)\n");
    scanf("%d",&m);
     
    }
    
 }
   
    printf("The array elements are as follows:\n");
    for(i=0;i<L1.lsize;i++)
        printf("%d\n",L1.arr[i]);
    m=1;
int y;
    while(m==1)
   {
   printf("Enter the postion of the element you want to delete:\n(must be lesser than %d)\n",L1.lsize);
    scanf("%d",&n1);
if(n1>=L1.lsize)
{printf("incorrect entry\ntry again:");
scanf("%d",&n1);
if(n1>=L1.lsize)
{
{printf("incorrect entry exit phase\n");
break;
}
}
}
else
    y=deletion(&L1,n1);
printf("do you want to delete more elements?(1/0)\n");
    scanf("%d",&m);
     
    }
    printf("the no. you deleted is: %d\n",y);
    
    printf("The array elements are as follows:\n");
    for(i=0;i<L1.lsize;i++)
        printf("%d\n",L1.arr[i]);
    int se,flag=0;
    m=1;
    while(m==1)
     {       
    printf("Enter the element you want to search\n");
    scanf("%d",&se);
    flag=search(&L1,se);
    if(flag==-1)
{    printf("the element was not found\n");
       break;}
    else
    {printf("the element %d was found at %d position\n",se,flag);}
    printf("do you want to search more elements?(1/0)\n");
    scanf("%d",&m);
    }
int em;
em=isempty(L1);
if(em==1)
printf("empty structure\n");
else 
printf("there is data in the structure\n");
int fu;
fu=isfull(L1);
if(fu==1)
printf("full structure\n");
else 
printf("there maybe data in the structure but its not full\n");
}
void insertion(struct list *pl,int pos,int x)
{
    int i;
    for(i=pl->lsize;i>=pos;i--)
        pl->arr[i+1]=pl->arr[i];
    pl->arr[pos]=x;
    pl->lsize++;
}
int deletion(struct list *pl,int pos)
{
    int i=0,x=pl->arr[i];
    for(i=pos+1;i<pl->lsize;i++)
        pl->arr[i-1]=pl->arr[i];
    (pl->lsize)--;
          return(x);
}
int search(struct list *pl, int x)
{
 int i,pos=-1;
for(i=0;i<=pl->lsize;i++)
          if(pl->arr[i]==x)
          {
                    pos=i;
                    break;
          }
return(pos);
}
int isempty(struct list l)
{
if(l.lsize==0)
return(1);
else
return(0);
}
int isfull(struct list l)
{
if(l.lsize==500)
return(1);
else
return(0);
}
