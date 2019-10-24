#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct polynode
{
int coeff;
int exp;
struct polynode *nptr;

};
struct polynode *hptr=NULL;
void insert(int pos,int x,int y)
{
 struct polynode *tmp = malloc(sizeof(struct polynode));
 tmp->coeff=x;
 tmp->exp=y;
 if(pos==1)
 {
    tmp->nptr=hptr;
    hptr=tmp;
 }
 else
 {
   int i=1;
   struct polynode *thptr=hptr;
   while(i<pos-1)
   {
    thptr=thptr->nptr;
    i++;
   }
   tmp->nptr=thptr->nptr;
   thptr->nptr=tmp;
 }

}
int Delete(int pos)
{
 struct polynode *thptr=hptr;
 int i=1,x,y;
 if(pos==1)
 {
  x=hptr->coeff;
  y=hptr->exp;
  hptr=hptr->nptr;
 }
 else
 {
  while(i<pos-1)
  {
   thptr=thptr->nptr;
   i++;
  }
  x=(thptr->nptr)->coeff;
  y=(thptr->nptr)->exp;
  thptr->nptr=(thptr->nptr)->nptr;
 }
 printf("you deleted %d x^%d",x,y);
 return(0);
}
void printList()
{
 printf("the polynomial is:\n");
 struct polynode *tmp=hptr;
 do
 {
  printf("%d x^%d + ",tmp->coeff,tmp->exp);
  tmp=tmp->nptr;
 }while(tmp!=NULL);
printf("0");
}
int isEmpty()
{
 if(hptr==NULL)
  return(1);
 else
  return(0);
}

int isFull()
{
 if(malloc(sizeof(struct polynode))==NULL)
  return(1);
 else
  return(0);
}
int Evaluate(int val)
{
    int eval=0,ex=0,t1=0;
struct polynode *tmp=hptr;
 do
 {
  ex=pow(val,tmp->exp);
  t1=tmp->coeff*ex;
  eval+=t1;
  tmp=tmp->nptr;
 }while(tmp!=NULL);
return(eval);
}






void main()
{
  int x,y,z,ch,m=1,e,pos,v,fval;
   while(m==1)
   {

   printf("What do you want to do?\n 1)insert\n 2)Delete\n 3)Print polynomial\n 4)Is full\n 5)Is Empty\n 6) Evaluate\n");
          scanf("%d",&ch);

   switch(ch)
          {
           case 1:
                    { z=isFull();
                              if(z==1)
                                        {printf("List full");
                                         break;}
                              else
                              {
                              printf("Enter the position u want to enter the node\n");
                              scanf("%d",&pos);
                              printf("Enter the Coefficient\n");
                              scanf("%d",&x);
                              printf("Enter the Power\n");
                              scanf("%d",&y);
                              insert(pos,x,y);
                              break;}
                    }
           case 2:
                    {
                        printf("Enter the position u want to delete\n");
                              scanf("%d",&pos);
                         e=Delete(pos);
                         break;
                    }
           case 3:
                    {
                       printList();
                       break;


                    }

           case 4:
                    {
                       printf("\nFull? : %d\n",isFull());
                       break;

                    }
          case 5:
                    {
                       printf("\nEmpty? : %d",isEmpty());
                       break;
                    }
          case 6:
            {
                printf("input the value of x:\n");
                scanf("%d",&v);
                fval=Evaluate(v);
                printf("The Evaluated polynomial value is:\n %d",fval);
                break;
            }

}
           printf("\n Do you want to try again?(1/0)");
           scanf("%d",&m);

}
}
