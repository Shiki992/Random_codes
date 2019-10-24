#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dll
{
    char song[300];
    struct dll *pptr;
    struct dll *nptr
};
struct dll *hptr=NULL;
struct dll *lptr=NULL;
struct dll *cptr=NULL;

/*void insert(int pos,char x)
{

int i=1;
 struct dll *tmp = malloc(sizeof(struct dll));
 struct dll *thptr = hptr;


 strcpy(tmp->song,x);
 if(pos==1)
 {
if(hptr==NULL)
{
lptr=tmp;
}
else
{
hptr->pptr=tmp;

}
tmp->nptr=hptr;
hptr=tmp;
    /*tmp->nptr=hptr;
    (tmp->nptr)->pptr=tmp;
    hptr=tmp;
    tmp->pptr=NULL;

 }
 else
 {
   /*int i=1;
   while(i<pos-1) //loop breaks when i= pos-1
   {
    thptr=thptr->nptr;
    i++;
   }
   tmp->pptr=thptr;
   tmp->nptr=thptr->nptr;
   (thptr->nptr)->pptr=tmp;
   thptr->nptr=tmp;
if(hptr==NULL)
{
lptr=tmp;
}
else
{
lptr->nptr = tmp; 
tmp->pptr = lptr;
}
lptr=tmp;
   }

 }

}*/
void inserta(char *s) {

   //create a song
   struct dll *tmp = malloc(sizeof(struct dll));
   
	strcpy(tmp->song,s);
   if(hptr==NULL) {
      //make it the lptr song
      lptr = tmp;
   } else {
      //update first pptr song
      hptr->pptr = tmp;
   }

   //point it to old first song
   tmp->nptr = hptr;
	
   //point first to new first song
   hptr = tmp;
}

int Delete(char *s)
{
 struct dll *thptr=hptr;
 int i=1,y,pos;
 char x[300];
 while(thptr!=NULL)
{   pos++;
    y=strcmp(thptr->song,s);
    if(y==1)
    {
        return (pos);
    }
    else
        return(-666);
}
 if(pos==1)
 {
  strcpy(x,hptr->song);
  (hptr->nptr)->pptr=NULL;
  hptr=hptr->nptr;
 }
 else
 {
  while(i<pos-1)
  {
   thptr=thptr->nptr;
   i++;
  }
  strcpy(x,(thptr->nptr)->song);
  (thptr->nptr)->pptr=thptr->pptr;
  (thptr->pptr)->nptr=thptr->nptr;
 }
 return(x);
}
void play(char *s)
{
    struct dll *thptr=hptr;
 int i=1,pos,y;
 char a[300],b[300],c[300];
 while(thptr!=NULL)
{   pos++;
    y=strcmp(thptr->song,s);
    if(y==1)
    {
        return (pos);
    }
    else
        return(-666);
}
while(i<pos)
{
    thptr=thptr->nptr;
   i++;
}
strcpy(thptr->song,b);
strcpy((thptr->pptr)->song,a);
strcpy((thptr->nptr)->song,c);
printf("\nthe song playing now:\n %s",b);
printf("nptr song:\n %s",c);
printf("pptrious song:\n %s",a);

}
void main()
{ char a[100],b[100],c[100];
scanf("%s",&a);
inserta(&a);
//insert(1,'b');
//insert(1,'c');
}

