#include<stdio.h>
#include<string.h>
struct book
{
          int acctno;
          char booktitle[100],author[100];
};
struct Library 
 {
          int top;
          struct book b[100];
 };
int push(struct Library *pl,int x,char *bt,char *at)
{
	if(pl->top==99)
		printf("Stack is full");
	else
	{
		pl->top=pl->top+1;
		pl->b[pl->top].acctno=x;
                    /*pl->b[pl->top].booktitle=bt;
                    pl->b[pl->top].author=at;*/
                    strcpy(pl->b[pl->top].booktitle,bt);
                    strcpy(pl->b[pl->top].author,at);

	}
	
}
void pop(struct Library *pl)
{
	
	int x=-1;
          char bt,at;
	if(pl->top==-1)
		printf("Stack is empty\n");
	else 
	{
		x=pl->b[pl->top].acctno;
                    bt=pl->b[pl->top].booktitle;
                    at=pl->b[pl->top].author;
		pl->top=pl->top-1;
	}
	return x;

}
int isfull(struct Library l)
{
	if(l.top==99)
		return 1;
	else 
		return 0;
}
int isempty(struct Library l)
{
	if(l.top==-1)
		return 1;
	else 
		return 0;
}
int search(struct Library *pl, int x)
{
 int i,pos=-1;
for(i=0;i<=pl->top;i++)
          if(pl->b[i].acctno==x)
          {
                    pos=i;
                    break;
          }
return(pos);
}

void main()
{
 struct Library l1;
 l1.top=-1;
 int x,veri=1;
 char aut[100],bot[100];
 while(veri==1)
{
  printf("enter the account number\n");
  scanf("%d",&x);
  printf("enter the book name\n");
  scanf("%s",bot);
  printf("enter the author name\n");
  scanf("%s",aut);
  push(&l1,x,bot,aut);
  printf("Do you want to push more elements?(1/0)\n");
  scanf("%d",&veri);
}
for(int i=l1.top;i>=0;i--)
{
printf("Acctno\t Book name\t Author name\t\n");
printf("%d\t %s\t %s\n",l1.b[i].acctno,l1.b[i].booktitle,l1.b[i].author);
}
veri=1;
while(veri==1)
{
printf("popping element.... \n. \n.\n");
pop(&l1);
for(int i=l1.top;i>=0;i--)
{
printf("Acctno\t Book name\t Author name\t\n");
printf("%d\t %s\t %s\n",l1.b[i].acctno,l1.b[i].booktitle,l1.b[i].author);
}
printf("Do you want to pop more elements?(1/0)\n");
  scanf("%d",&veri);

}
veri=1;
int se,flag;
    while(veri==1)
     {       
    printf("Enter the element you want to search\n");
    scanf("%d",&se);
    flag=search(&l1,se);
    if(flag==-1)
{    printf("the element was not found\n");
       break;}
    else
    {printf("the element %d was found at %d position\n",se,flag);}
    printf("do you want to search more elements?(1/0)\n");
    scanf("%d",&veri);
    }
int em;
em=isempty(l1);
if(em==1)
printf("empty structure\n");
else 
printf("there is data in the structure\n");
int fu;
fu=isfull(l1);
if(fu==1)
printf("full structure\n");
else 
printf("there maybe data in the structure but its not full\n");


}
 
