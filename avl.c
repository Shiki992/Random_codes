#include<stdio.h>
#include<stdlib.h>
struct Tnode
{
	struct Tnode *lcptr;
	int Aadhar;
	int Mobile;
	int height;
   struct Tnode *rcptr;
}*rptr=NULL;
struct Tnode* insert(struct Tnode *ptr,int x,int y);
void updateheight(struct Tnode *ptr);
int findheight(struct Tnode *ptr);
struct Tnode* RotateRight(struct Tnode *ptr);
struct Tnode* RotateLeft(struct Tnode *ptr);
struct Tnode* RotateRightLeft(struct Tnode *ptr);
struct Tnode* RotateLeftRight(struct Tnode *ptr);
int printno(struct Tnode *ptr,int y);
void print(struct Tnode *ptr);

void main()
{
	int x,y;
	int n=0;
    int flag = 0;
    int choice;
    while(n==0)
    {
        printf("1:Insert \n2:Print \n3:Search \n4:Exit\nChoice: ");
        scanf("%d", &choice);
        if(choice == 4)
        {
            flag = 1;
            n=1;
            break;
        }
        else
        {
            char bokName[30];
            switch(choice)
            {
                case 1: 
                { printf("\nEnter Aadhar no. to Insert:\n");
                	scanf("%d",&x);
                	printf("\nEnter Mobile no. to Insert:\n");
                	scanf("%d",&y);

                	rptr=insert(rptr,x,y);
                	break;
                }
                case 3: 
                {printf("\nEnter Aadhar no. to Search:\n");
                	scanf("%d",&x);
                 	int w=printno(rptr,x);   
                 	break;
                }
                case 2: 
                {
                	printf("Aadhar\t Mob\t BF\n");
                	print(rptr);
                	break;
                }
                
               


                default: printf("Please Enter the right choice\n");
            }
        }
    }
	
}
struct Tnode* insert(struct Tnode *ptr,int x,int y)
{  
	if(ptr==NULL)
   {
   	ptr=malloc(sizeof(struct Tnode));
		ptr->Mobile=y;
		ptr->Aadhar=x;	
		ptr->lcptr=NULL;
		ptr->rcptr=NULL;
		ptr->height=0;
	}
	else
	{
		if(x<ptr->Aadhar)
		{
			ptr->lcptr=insert(ptr->lcptr,x,y);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==2 ||findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2)
			{
				
				if(x<ptr->lcptr->Aadhar)
					ptr=RotateRight(ptr);
				else
					ptr=RotateLeftRight(ptr);
			} 
		}
		else
		{
			ptr->rcptr=insert(ptr->rcptr,x,y);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==2 ||findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2)
			{
				if(x>ptr->rcptr->Aadhar)
					ptr=RotateLeft(ptr);
				else
					ptr=RotateRightLeft(ptr);
			} 
		}		
	}
	updateheight(ptr);
   return ptr;
}
int findheight(struct Tnode *ptr)
{
	int h1,h2;
	if(ptr==NULL)
	{
		return -1;
	}
	else
	{
 		h1 = findheight(ptr->lcptr);
		h2= findheight(ptr->rcptr);
		if(h1<h2)
			return h2+1;
		else
			return h1+1;
	}
}
void updateheight(struct Tnode *ptr)
{	
   
   int h1,h2;
	if(ptr->lcptr==NULL)
	{
		h1=-1;
	}
	else
		h1=ptr->lcptr->height;
	if(ptr->rcptr==NULL)
	{
		h2=-1;
	}
	else
		h2=ptr->rcptr->height;
	if(h1<h2)
		ptr->height=h2+1;		
	else
		ptr->height=h1+1;
}
struct Tnode* RotateRight(struct Tnode *ptr)
{
	struct Tnode *jptr=ptr;
	struct Tnode *kptr=ptr->lcptr;
	jptr->lcptr=kptr->rcptr;
	kptr->rcptr=jptr;
	updateheight(jptr);
	updateheight(kptr);
	return kptr;
}
struct Tnode* RotateLeft(struct Tnode *ptr)
{
	struct Tnode *jptr=ptr;
	struct Tnode *kptr=ptr->rcptr;
	jptr->rcptr=kptr->lcptr;
	kptr->lcptr=jptr;
	updateheight(jptr);
	updateheight(kptr);
	return kptr;
}
struct Tnode* RotateLeftRight(struct Tnode *ptr)
{
	struct Tnode *jptr=ptr;
	struct Tnode *kptr=ptr->lcptr;
	ptr->lcptr=RotateLeft(kptr);
	return(RotateRight(jptr));
}
struct Tnode* RotateRightLeft(struct Tnode *ptr)
{
	struct Tnode *jptr=ptr;
	struct Tnode *kptr=ptr->rcptr;
	ptr->rcptr=RotateRight(kptr);
	return(RotateLeft(jptr));
}

int printno(struct Tnode *ptr,int y)
{
	if(ptr==NULL)
		return 0;
	if(ptr!=NULL)
{ 
	
	if(ptr->Aadhar==y)
	{
	printf("Aadhar:%d\t Mobile:%d \n",ptr->Aadhar,ptr->Mobile);	
	}
	else if(y<ptr->Aadhar)
		printno(ptr->lcptr,y);
	else
		printno(ptr->rcptr,y);;
}
	
	return 0;
}

void print(struct Tnode *ptr)
{
	int i=0;

	if(ptr!=NULL)
	{ 
		print(ptr->lcptr);
		i=findheight(ptr->lcptr)-findheight(ptr->rcptr);
		printf("%d\t %d\t %d\n",ptr->Aadhar,ptr->Mobile,i);
		print(ptr->rcptr);
		
	}
}


