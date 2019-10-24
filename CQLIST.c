#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *nptr;
};
struct node *hptr=NULL;
struct node *fptr=NULL;
struct node *rptr=NULL;

//Queue
void insertcq(int x)
{
 struct node *tmp = malloc(sizeof(struct node));
 tmp->data=x;
 tmp->nptr=NULL;
 if(fptr==NULL)
 {
   
   fptr=rptr=tmp;
   rptr->nptr=tmp;
}
 else 
 {
          rptr->nptr=tmp;
          rptr=tmp;
 }

}
void printListcq()
{
 struct node *tmp=fptr;
 do
 {
  printf("%d \n",tmp->data);
  tmp=tmp->nptr;
 }while(tmp!=NULL);
}

int Deletecq()
{

 int x;
if(fptr==NULL)
printf("dequeue failed!!!!\n");
else
{
x=fptr->data;
fptr=fptr->nptr;

}
if(fptr==NULL)
rptr=NULL;

 return(x);
}






//stack
void push(int value)
{
   struct node *tmp;
   tmp = (struct node*)malloc(sizeof(struct node));
   tmp->data = value;
   if(hptr == NULL)
      tmp->nptr = NULL;
   else
      tmp->nptr = hptr;
   hptr = tmp;
   printf("\nInsertion is Success!!!\n");
}
void pop()
{
   if(hptr == NULL)
      printf("\nStack is Empty!!!\n");
   else{
      struct node *temp = hptr;
      printf("\nDeleted element: %d", temp->data);
      hptr = temp->nptr;
      free(temp);
   }
}
void display()
{
   if(hptr == NULL)
      printf("\nStack is Empty!!!\n");
   else {
      struct node *temp = hptr;
      while(temp->nptr != NULL){
	 printf("%d\n",temp->data);
	 temp = temp -> nptr;
      }
      printf("%d\n",temp->data);
   }
}


//empty and full
int isEmpty()
{
 if(hptr==NULL)
  return(1);
 else
  return(0);
}

int isFull()
{
 if(malloc(sizeof(struct node))==NULL)
  return(1);
 else
  return(0);
}



















//main
void main()
{
    int op,m=1;
    while(m==1)
    {

    printf("1.Stack\n2.Queue\n3.Exit\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
    {
    int cho, val,n=1;
   printf("\n:: Stack using Linked List ::\n");
   while(n==1){
      printf("\nWhat would you like to do?\n");
      printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&cho);
      switch(cho)
      {
	 case 1:   if(isFull()==1)
                    {printf("push impossible!!");
                    break;}
                     printf("Enter the value to be insert: ");
		 scanf("%d", &val);
		 push(val);
		 break;
	 case 2: if(isEmpty()==1)
                   {printf("pop impossible!!");
                    break;}
                    pop();
                     break;
	 case 3: display(); break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
     }
}
     case 2:
        {
         int cho, val,pos,n=1;
   printf("\n::  Queue using Linked List ::\n");
   while(n==1){
      printf("\nWhat would you like to do?\n");
      printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&cho);
      switch(cho)
      {
	 case 1: {
                    if(isFull()==1)
                    {printf("enqueue impossible!!");
                    break;}
                    else{
                    printf("Enter the value to be insert: ");
		 scanf("%d", &val);
		 insertcq(val);
		 break;}
                    }
	 case 2: {
	    if(isEmpty()==1)
                    {printf("dequeue impossible!!");
                    break;}
                    else
	     {int c=Deletecq(pos);
                    printf("%d",c);
	 break;
	 }
	 case 3: printListcq(); break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");

        }
}
}
}
case 3:exit(0);
default:printf("\nWrong selection!!! Please try again!!!\n");
}

    }
}
