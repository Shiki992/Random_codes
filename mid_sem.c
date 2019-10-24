#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct dll
{
int *pptr;
int x;
int *nptr;
}*hptr=NULL,*lptr=NULL,*cptr=NULL;

int inserta(int s,int pos) 
{
   struct dll *tmp = malloc(sizeof(struct dll));
int i=1;
   tmp->x=s; 
  if(pos==1)
{
   if(hptr==NULL)
   {
      
      hptr=tmp;
      tmp->nptr = NULL;
   }
 else
   {      
      hptr->pptr = tmp;
      tmp->nptr=hptr;
      hptr = tmp;
   }
 }
else
{
 struct dll *thptr=hptr;
while(i<pos-1)
{
thptr=thptr->nptr;
i++;
}
thptr->nptr=tmp;
tmp->pptr=thptr;

}
return i;
}  
 


int print(int pos)
{
struct dll *thptr=hptr;
int i=0;
printf("%d\n%d\n",thptr->x,thptr);
while(i<pos)
{
thptr=thptr->nptr;
i++;
printf("%d\n%d\n",thptr->x,thptr);
}

}
int delete(int pos)
{
struct dll *thptr=pos;
int i=1;
/*while(i<pos)
{
thptr=thptr->nptr;
i++;
}*/

int a=thptr->x;
lptr=thptr->nptr;
cptr=thptr->pptr;
if(cptr==NULL)
{
hptr=thptr->nptr;
hptr->pptr=NULL;
}
else if(lptr==NULL)
{
thptr->nptr=NULL;
}
else
{
cptr->nptr=thptr->nptr;
lptr->pptr=thptr->pptr;

}
return a;
}

void main()
{
int m=0,n;
m=inserta(6,1);
m=inserta(8,2);
m=inserta(5,3);
m=inserta(9,4);
m=inserta(75,5);
m=inserta(69,6);
m=inserta(55,7);
print(m);
printf("type address of element you want to delete:\n");
scanf("%d",&n);
int d=delete(n);
printf("deleted element=%d\n",d);
m--;

print(m);

}
