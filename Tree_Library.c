#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book
{
          int acctno;
          char booktitle[100],author[100];
};
struct Tnode
{
	struct book b;
	struct Tnode *lcptr;
	struct Tnode *rcptr;
};
struct Tnode *rptr=NULL;
void insert(char *x,char *y,int t)
{
   struct Tnode *tmp=malloc(sizeof(struct Tnode));
	strcpy(tmp->b.booktitle,x);
          strcpy(tmp->b.author,y);
          tmp->b.acctno=t;
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
        
     int q;
     q=strcmp(ptr->b.booktitle,x);
     if(q>1)
          {         
            ptr=ptr->rcptr;
          }
     else
          {
           ptr=ptr->lcptr;         
          }
}
 int r=strcmp(pptr->b.booktitle,x);
    
 if(r<1)
          pptr->lcptr=tmp;
     else
	pptr->rcptr=tmp;
}

}
void Inorder(struct Tnode *ptr)
{
	if(ptr!=NULL)
	{
		Inorder(ptr->rcptr);
		printf("%s\t %s\t %d \n",ptr->b.booktitle,ptr->b.author,ptr->b.acctno);
		Inorder(ptr->lcptr);
	}
}
/*struct Tnode* delete(struct Tnode *m,char *x)
{
	char a[100]="-666";
          
   printf("Hello");
	struct Tnode *ptr=rptr;
	struct Tnode *pptr=NULL;
          int r=0,q=0;
          printf("Hello");
		
          while(ptr!=NULL && q!=0)
	{
		q=strcmp(ptr->b.booktitle,x);
		pptr=ptr;

		if(q>0)
			{
				ptr=ptr->lcptr;
            }
		else if (q<0)
		{
		ptr=ptr->rcptr;

		}
         q=strcmp(ptr->b.booktitle,x);
         
          
	}
printf("Hello");
r=strcmp(pptr->b.booktitle,x);
	if(ptr==NULL)
	{
		printf("\n Deletion Fails");
	}
	else if(rptr->lcptr==NULL && rptr->rcptr==NULL)
	{
		strcpy(a,rptr->b.booktitle);
		rptr=NULL;
	}
	else if(ptr->lcptr==NULL && ptr->rcptr==NULL) //Case 1:Delete Leaf Node
	{
		strcpy(a,ptr->b.booktitle);
		if(r<0)
			pptr->lcptr=NULL;
		else
			pptr->rcptr=NULL;
	}
	else if(ptr->lcptr==NULL && ptr->rcptr!=NULL || ptr->lcptr!=NULL && ptr->rcptr==NULL)
	{
		strcpy(a,ptr->b.booktitle);
		if(x<pptr->b.booktitle && ptr->lcptr!=NULL)
			pptr->lcptr=ptr->lcptr;
		else if(r<0 && ptr->lcptr==NULL)
			pptr->lcptr=ptr->rcptr;
		else if(r>=0 && ptr->lcptr!=NULL)
			pptr->rcptr=ptr->lcptr;
		else
			pptr->rcptr=ptr->rcptr;
	}
	else
	{
		struct Tnode *tmp=ptr;
     
		tmp=tmp->rcptr;

		while(tmp->lcptr!=NULL)
		{
       
			tmp=tmp->lcptr;
		}

       strcpy(a,ptr->b.booktitle);
       strcpy(ptr->b.booktitle,tmp->b.booktitle);
delete(&tmp,tmp->b.booktitle);
     }

	return m;
}*/
struct Tnode* delete(struct Tnode* root, char* key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    if (key==root->b.booktitle) 
        {rptr=NULL;
        	return NULL;} 
    // then it lies in left subtree 
    if (key<root->b.booktitle) 
        root->lcptr = delete(root->lcptr, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->b.booktitle) 
        root->rcptr = delete(root->rcptr, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->lcptr == NULL) 
        { 
            struct node *temp = root->rcptr; 
            free(root); 
            return temp; 
        } 
        else if (root->rcptr == NULL) 
        { 
            struct node *temp = root->lcptr; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct Tnode* current = root; 
  
    /* loop down to find the leftmost leaf */
    while (current->lcptr != NULL) 
        current = current->lcptr; 
        struct Tnode* temp = current; 
  
        // Copy the inorder successor's content to this node 
        strcpy(root->b.booktitle,temp->b.booktitle); 
  
        // Delete the inorder successor 
        root->rcptr = delete(root->rcptr, temp->b.booktitle); 
    } 
    return root; 
}

void main()
{ 
int x=1,s,ch;
char k[100],l[100];
 while(x==1)
   {
   
   printf("What do you want to do?\n 1)Insert\n 2)Delete\n 3)Print\n ");
          scanf("%d",&ch);
          
   switch(ch)       
          {
           case 1:
                    {                         
                              printf("Enter the acct no.\n");
                              scanf("%d",&s);
                              printf("Enter the book name\n");
                              scanf("%s",k);
                              printf("Enter the author's name\n");
                              scanf("%s",l);                              
                              insert(k,l,s);  
                              break;              
                    }
           case 2:
                    {
                         printf("Enter the book name to delete:\n");
                              scanf("%s",k);
                         struct Tnode *u=NULL;

                         u=delete(&rptr,k); 
                        printf("\n Delete successful\n");
                         break;         
                    }
           case 3:
                    {
                       Inorder(rptr);
                       

                    }        
          

}
           printf("Do you want to try again?(1/0)");
           scanf("%d",&x);

   }
}
