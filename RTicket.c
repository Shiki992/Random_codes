#include<stdio.h>
#include<string.h>

struct Passenger
{
       int pnr;
       char name[100];
       int fare;
};
struct wlq
{
        struct Passenger w[100];
        int rear;
        int front;

};
struct clq
{
        struct Passenger cw[100];
        int rear;
        int front;

};
int isfull(struct wlq *l)
{
	if(l->rear==99)
		return 1;
	else 
		return 0;
}
int isempty(struct wlq *l)
{
	if(l->rear==-1)
		return 1;
	else 
		return 0;
}

int enqueue(struct wlq *pw, char *n,int x)
{
          int e=isempty(&pw);
          int f=isfull(&pw);
          if(f==1)
          {
           printf("the waiting list is full\n");
           
          }
          if(e==1)
          {
           pw->front++;
           pw->rear++;
           pw->w[pw->front].pnr=pw->rear+1;
           pw->w[pw->front].fare=x;
           strcpy(pw->w[pw->front].name,n);
          }
          else
          {
           pw->rear++;
           pw->w[pw->rear].pnr=pw->rear+1;
           pw->w[pw->rear].fare=x;
           strcpy(pw->w[pw->rear].name,n);
          }
}
int xenqueue(struct clq *pw, struct Passenger p)
{
          int e=isempty(&pw);
          int f=isfull(&pw);
          if(f==1)
          {
           printf("the waiting list is full\n");
           
          }
          if(e==1)
          {
           pw->front++;
           pw->rear++;
           /*pw->cw[pw->front].pnr=pw->rear+1;
           pw->cw[pw->front].fare=x;
           strcpy(pw->cw[pw->front].name,n);*/
           pw->w[pw->front]=p;
          }
          else
          {
           pw->rear++;
           pw->cw[pw->rear].pnr=pw->rear+1;
           pw->cw[pw->rear].fare=x;
           strcpy(pw->cw[pw->rear].name,n);
          }
}
int dequeue(struct wlq *pw,struct clq *pw2)
{
          int e=isempty(pw);
          
          if(e==1)
          {
           printf("the waiting list is empty, nothing to remove\n");
           
          }
          xenqueue(&pw2,pw->w[pw->front].name,pw->w[pw->front].fare);
          pw->front++;
          if(pw->rear==pw->front)
          {
           printf("Waiting list reset\n");
           pw->front=-1;
           pw->rear=-1;
          }

}
int print(struct wlq *pw)
{int i;
for(int i=pw->front+1;i<=pw->rear;i++)
          {
           
           printf("%d\t %s\t %d\n",pw->w[i].pnr,pw->w[i].name,pw->w[i].fare);
          }
}
int printx(struct clq *pw)
{int i;
for(int i=0;i<=pw->rear;i++)
          {
           
           printf("%d\t %s\t %d\n",pw->cw[i].pnr,pw->cw[i].name,pw->cw[i].fare);
          }
}
void main()
{
struct wlq w1;
struct clq w2;
w1.rear=w1.front=-1;
w2.rear=w2.front=-1;
int pno,price,veri=1,cho;
char name[100];
while(veri==1)
{
label:
printf("Enter\n 1:Enqueue \n 2:Dequeue\n 3:Print\n");
scanf("%d",&cho);
switch(cho)
{
case 1:
{

          printf("Enter Passenger name\n");
          scanf("%s",&name);
          printf("Enter Price Passenger paid\n");
          scanf("%d",&price);
          enqueue(&w1,name,price);
           printf("Enqueue Successful! Do you want to try again?(1/0)\n");
           scanf("%d",&veri);
           if(veri==1)
           goto label;
           else
           break;
}
case 2:
{
          dequeue(&w1,&w2);
           printf("Dequeue Successful! Do you want to try again?(1/0)\n");
           scanf("%d",&veri);
           if(veri==1)
           goto label;
           else
           break;
}
case 3:
{         printf("waiting list:\n");
          printf("pno\t Passenger name\t Price\t\n"); 
          print(&w1);   
          printf("Confirmed list\n");
          printf("pno\t Passenger name\t Price\t\n"); 
          printx(&w2);          
          printf("Print Successful! Do you want to try again?(1/0)\n");
           scanf("%d",&veri);
           if(veri==1)
           goto label;
           else
           break;      
          
}
default:  {
           
           printf("you made an incorrect choice! Do you want to try again?(1/0)");
           scanf("%d",&veri);
           if(veri==1)
           goto label;
           else
           break;
          }

}
}
return 0;
}
