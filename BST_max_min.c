#include<stdio.h>
#include<stdlib.h>
struct Tnode
{
	int data;
	struct Tnode *lcptr;
	struct Tnode *rcptr;
};
struct Tnode *rptr=NULL;

void insert(int x)
{
   struct Tnode *tmp=malloc(sizeof(struct Tnode));
	tmp->data=x;
	tmp->lcptr=NULL;
   tmp->rcptr=NULL;
   if(rptr==NULL)
	{	
		rptr=tmp;
	}
	else
	{
		struct Tnode *ptr=rptr;
		struct Tnode *pptr=NULL;
      while(ptr!=NULL)
		{
			pptr=ptr;
         if(x<ptr->data)
			{
				ptr=ptr->lcptr;	
			}
			else
			{
				ptr=ptr->rcptr;
			}
		}
		if(x<pptr->data)
			pptr->lcptr=tmp;
		else
			pptr->rcptr=tmp;	
	}	

}
void Inorder(struct Tnode *ptr)
{
	if(ptr!=NULL)
	{
		Inorder(ptr->lcptr);
		printf("%d\n ",ptr->data);
		Inorder(ptr->rcptr);
	}
}
int delete(int x)
{
	int b=-666;	
   struct Tnode *ptmp=NULL;
	struct Tnode *ptr=rptr;
	struct Tnode *pptr=NULL;	
	while(ptr!=NULL && ptr->data!=x)
	{
		pptr=ptr;		
		if(x>=ptr->data)
			ptr=ptr->rcptr;	
		else 
			ptr=ptr->lcptr;
	}	
	if(ptr==NULL)
	{
		printf("\n Deletion Fails");
	}
	else if(rptr->lcptr==NULL && rptr->rcptr==NULL)
	{
		b=rptr->data;		
		rptr=NULL;	
	}
	else if(ptr->lcptr==NULL && ptr->rcptr==NULL) //Case 1:Delete Leaf Node
	{
		b=ptr->data;		
		if(x<pptr->data)
			pptr->lcptr=NULL;
		else
			pptr->rcptr=NULL;
	}
	else if(ptr->lcptr==NULL && ptr->rcptr!=NULL || ptr->lcptr!=NULL && ptr->rcptr==NULL)
	{
		b=ptr->data;		
		if(x<pptr->data && ptr->lcptr!=NULL)
			pptr->lcptr=ptr->lcptr;		
		else if(x<pptr->data && ptr->lcptr==NULL)
			pptr->lcptr=ptr->rcptr;
		else if(x>=pptr->data && ptr->lcptr!=NULL)
			pptr->rcptr=ptr->lcptr;
		else
			pptr->rcptr=ptr->rcptr;   
	}
	else
	{		
		struct Tnode *tmp=ptr;
      ptmp=tmp;		
		tmp=tmp->rcptr;
      
		while(tmp->lcptr!=NULL)
		{
         ptmp=tmp;
			tmp=tmp->lcptr;
		}
		b=ptr->data;		
		ptr->data=tmp->data;	
			

		//To delete suc node pointed to by tmp, and its parent is ptmp
      
       if(tmp->data < ptmp->data)
         ptmp->lcptr=tmp->rcptr;
       else
        ptmp->rcptr=tmp->rcptr;

	}
	return b;
}
void Preorder(struct Tnode* node) 
{ 
     if (node == NULL) 
          return; 
  
     /* first print data of node */
     printf("%d \n", node->data);   
  
     /* then recur on left sutree */
     Preorder(node->lcptr);   
  
     /* now recur on right subtree */
     Preorder(node->rcptr); 
}     
void Postorder(struct Tnode* node) 
{ 
     if (node == NULL) 
        return; 
  
     // first recur on left subtree 
     Postorder(node->lcptr); 
  
     // then recur on right subtree 
     Postorder(node->rcptr); 
  
     // now deal with the node 
     printf("%d \n", node->data); 
} 
int Max(struct Tnode *root)
{ 
    // Base case 
    if (root == NULL) 
      return 0; 
  
     
    int res = root->data; 
    int lres = Max(root->lcptr); 
    int rres = Max(root->rcptr); 
    if (lres > res) 
      res = lres; 
    if (rres > res) 
      res = rres; 
    return res; 
} 
int Min(struct Tnode *root)
{ 
  struct Tnode* current = root; 
  
  /* loop down to find the leftmost leaf */
  while (current->lcptr != NULL) { 
    current = current->lcptr; 
  } 
  return(current->data); 
} 
void main()
{
   	int x,n=0;
    int flag = 0;
    int choice;
    while(n==0)
    {
        printf("1: Insert \n2: Delete  \n3: Print Inorder \n4: Print Preorder \n5: Print Postorder \n6: Min and Max \n7:Exit\nChoice: ");
        scanf("%d", &choice);
        if(choice == 7)
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
                { printf("\nEnter no. to Insert:\n");
                	scanf("%d",&x);
                	insert(x);
                	break;
                }
                case 2: 
                {printf("\nEnter no. to Delete:\n");
                	scanf("%d",&x);
                 	delete(x);   
                 	break;
                }
                case 3: 
                {
                	Inorder(rptr);
                	break;
                }
                case 4: 
                {
                   Preorder(rptr);
                   break; 
                }
                case 5:
                {
                	Postorder(rptr);
                	break;
                }
                case 6:
                {
                	int a=Max(rptr);
   					int b=Min(rptr);
   					printf("\nmax= %d\n min=%d\n",a,b );
                	break;
                }


                default: printf("Please Enter the right choice\n");
            }
        }
    }
	
}
