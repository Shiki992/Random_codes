#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
 int data;
 struct node *nptr;
};
struct node *hptr=NULL;
void push(int value)
{
   struct node *tmp;
   while(value!=0)
{
   tmp = (struct node*)malloc(sizeof(struct node));
   tmp->data = value;
   if(hptr == NULL)
      tmp->nptr = NULL;
   else
      tmp->nptr = hptr;
   hptr = tmp;
value-=1;
}
   printf("\nInsertion is Success!!!\n");
}

void display()
{
   if(hptr == NULL)
      printf("\nStack is Empty!!!\n");
   else {
      struct node *temp = hptr;
      while(temp->nptr != NULL)
{
	 printf("%d\n",temp->data);
	 temp = temp -> nptr;
      }
      printf("%d\n",temp->data);
   }
}
int eval()

{ int eval=1;
   if(hptr == NULL)
      printf("\nStack is Empty!!!\n");
   else {
      struct node *temp = hptr;
      while(temp->nptr != NULL)
{           eval=eval*temp->data;
	 printf("%d \n",eval);
	 temp = temp -> nptr;
      }
      eval=eval*temp->data;
   }
return(eval);
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
void main()
{
    int cho, val,n=1,x;
   printf("\n:: Stack using Linked List ::\n");
   while(n==1){
      printf("\nWhat would you like to do?\n");
      printf("1. Push\n2.Evaluate\n3. Display\n4. Exit\n");
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
	 case 2: x=eval();
                    printf("\n the value of %d ! is %d \n",val,x);
                     break;
	 case 3: display(); break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
     }
}
