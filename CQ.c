#include<stdio.h>
struct CQueue
{
   int a[5];
   int front;
   int rear;
};
void enqueue(struct CQueue *q,int x);
int dequeue(struct CQueue *q);
void print(struct CQueue q);
void main()
{
   //Create empty queue
   int y,z,ch,x=1,s,m,n;
   struct CQueue q1;
   q1.front=-1;
   q1.rear=-1;
   while(x==1)
   {
   
   printf("What do you want to do?\n 1)Enqueue\n 2)Dequeue\n 3)Print queue\n 4)Is full\n 5)Is Empty");
          scanf("%d",&ch);
          
   switch(ch)       
          {
           case 1:
                    { z=isfull(q1);
                              if(z==1)
                                        {printf("Qfull");
                                         break;}
                              else
                              {                          
                              printf("Enter the Element\n");
                              scanf("%d",&s);
                                                            
                              enqueue(&q1,s);  
                              break;}               
                    }
           case 2:
                    {
                         y=dequeue(&q1);  
                         printf("Deleted Element: \n %d \n ",y);
                         break;         
                    }
           case 3:
                    {
                       print(q1);  
                       

                    }        
          
           case 4:
                    {
                       printf("\nFull? : %d\n",isfull(q1));
                    }
          case 5:
                    {
                       printf("\nEmpty? : %d",isempty(q1));
                    }

}
           printf("Do you want to try again?(1/0)");
           scanf("%d",&x);

   }
   
   
 
   printf("\nEmpty? : %d",isempty(q1));
   printf("\nFull? : %d\n",isfull(q1));
}
void enqueue(struct CQueue *q,int x) 
{
   if((q->rear+1)%5==q->front)
      printf("\nQueue is full");
   else if(q->front==-1)
   {
      q->a[0]=x;
      q->front=0;
      q->rear=0;
   }
   else 
   {
      q->rear=(q->rear+1)%5;
      q->a[q->rear]=x;
   }
}
int dequeue(struct CQueue *q)
{
   int x;
   if(q->rear==-1)
   {   
      printf("\nQueue is empty");
      return -666;
   }
   else if(q->front==q->rear)
   {
      x=q->a[q->front];
      q->front=-1;
      q->rear=-1;
      return x;
   }
   else 
   {
      x=q->a[q->front];
      q->front=(q->front+1)%5;
      return x;
   }
}
int isfull(struct CQueue q)
{
   if((q.rear+1)%5==q.front)
      return 1;
   else 
      return 0;      
}
int isempty(struct CQueue q)
{
   if(q.rear==-1)
      return 1;
   else 
      return 0;
}
      
void print(struct CQueue q)
{
  int i;
  for( i=q.front; i!=q.rear;i=(i+1)%5)
          {
           printf("%d \n",q.a[i]); 
          }
  printf("%d \n",q.a[i]);
}   
