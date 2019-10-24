#include<stdio.h>
#include<stdlib.h>
struct Element
{
	int data;
	struct Element *nptr;
};
struct Element *uptr=NULL,*aptr=NULL,*bptr=NULL,*iptr=NULL,*unptr=NULL;

struct Element* insert(struct Element *hptr,int y)
{
 struct Element *tmp = malloc(sizeof(struct Element));
 //struct Element *cptr = uptr;
  	tmp->data=y;
 
    tmp->nptr=hptr;
    hptr=tmp;
    return hptr;	

 /*else 
 	{
 		while(cptr!=NULL)
 		{
 			if(cptr->data==y)
 			{
 				tmp->data=y;
 
    			tmp->nptr=hptr;
    			hptr=tmp;
    			cptr=uptr;
    			return hptr;
 			}
 			else 
 				cptr=cptr->nptr;
 						

 			cptr=cptr->nptr;
 			if(cptr==NULL)
 			{
 				printf("impossible to insert\n");
 				return NULL;
 			}
 		}
 		
 			cptr=uptr;
 	}*/
 

 
}
struct Element* Common(struct Element *ptr,struct Element *xptr)
{
	struct Element *tmp=ptr;
	struct Element *tmp1=xptr;

	while(tmp!=NULL)
	{
		while(tmp1!=NULL)
		{
			if(tmp->data==tmp1->data)
		
			{struct Element *tmpe = malloc(sizeof(struct Element));
  	tmpe->data=tmp1->data;
 
    tmpe->nptr=iptr;
    iptr=tmpe;
    }
				tmp1=tmp1->nptr;
		
		
		}
		tmp=tmp->nptr;
		tmp1=xptr;

	}
 return iptr;
}

struct Element* Union(struct Element *optr,struct Element *tptr)
{
	 struct Element *tmp = malloc(sizeof(struct Element));
	 tmp->data=optr->data;
	 tmp->nptr=NULL;
	 unptr=tmp;
	 struct Element *tmp1 =optr->nptr;
	 struct Element *tmp2 =tptr;
	while(tmp1!=NULL)
	{
	struct Element *tmp5 = malloc(sizeof(struct Element));
	 tmp5->data=tmp1->data;
	 
	 tmp5->nptr=unptr;
	 unptr=tmp5;
	 tmp1=tmp1->nptr;

	}
	int flag;
	while(tmp2!=NULL)
	{
		flag=0;
		tmp1=unptr;
		while(tmp1!=NULL)
		{
		if(tmp2->data==tmp1->data)
		{
			flag=1;
			break;
		}
		tmp1=tmp1->nptr;
		}
		if(flag==0)
		{
			struct Element *tmp7 = malloc(sizeof(struct Element));
			tmp7->data=tmp2->data;
			tmp7->nptr=unptr;
	 		unptr=tmp7;
		}
		tmp2=tmp2->nptr;

	}
	return unptr;
}
void printList(struct Element *hptr)
{
 printf("the set is:\n");
 struct Element *tmp=hptr;
 do
 {
  printf("%d \n",tmp->data);
  tmp=tmp->nptr;
 }while(tmp!=NULL);

}

void main()
{
	uptr=insert(uptr,10);
	uptr=insert(uptr,9);
	uptr=insert(uptr,8);
	uptr=insert(uptr,7);
	uptr=insert(uptr,6);
	uptr=insert(uptr,5);
	uptr=insert(uptr,4);
	uptr=insert(uptr,3);
	uptr=insert(uptr,2);
	uptr=insert(uptr,1);
	printf("the set U  is:\n");
	printList(uptr);
	aptr=insert(aptr,5);
	aptr=insert(aptr,4);
	aptr=insert(aptr,3);
	aptr=insert(aptr,2);
	aptr=insert(aptr,1);
	printf("the set A  is:\n");
	printList(aptr);
	bptr=insert(bptr,2);
	bptr=insert(bptr,8);
	bptr=insert(bptr,7);
	bptr=insert(bptr,6);
	bptr=insert(bptr,5);
	printf("the set B  is:\n");
	printList(bptr);
	iptr=Common(aptr,bptr);
	printf("the intersection set is:\n");
	printList(iptr);
	printf("the Union set  is:\n");
		unptr=Union(aptr,bptr);

	printList(unptr);



	
}