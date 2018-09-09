#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *pre;
	struct node *nxt;
}NODE;

NODE*header;
void reverse();
void show();
void reverse();
void del_at_pos();
void del_at_last();
void del_at_beg();
void insert_at_pos();
void insert_at_last();
void insert_at_beg();
void traverse();
void createdoublylinklist();
int main()
{
	int ch;
	printf("enter choice\n");
	printf("1.create doubly circular link list\n2.exit\t");
	scanf("%d",&ch);

	switch(ch)
	{
	     case 1: createdoublylinklist();break;
	     case 2 :
	     default :exit(0);
    }
return 0;
}

void createdoublylinklist()
{

	NODE*ptr,*cpt;
	int cre,ch=1;
	printf("enter elemnt");
	ptr=(NODE*)malloc(sizeof(NODE));
	scanf("%d",&ptr->data);
	header=ptr;

    printf("do you want to continue press 1 else 0\t");
    scanf("%d",&cre);
	while(cre==1)
	{
		cpt=(NODE*)malloc(sizeof(NODE));
		printf("enter value");
		scanf("%d",&cpt->data);
		ptr->nxt=cpt;
		cpt->pre=ptr;
		ptr=cpt;
		printf("do you want to continue press 1 else 0\t");
		scanf("%d",&cre);
	}
	ptr->nxt=header;
	header->pre=ptr;

	printf("enter choice\n");
	printf("1.traverse\n2.insert at begining\n3.insert at last\n4.insert at position\n5.delete at begining\n6.delete at last\n7.delete at position\n8.reverse\n9.exit\t");
	scanf("%d",&ch);
	while(ch!=9)
	{

	switch(ch)
	     {
		 case 1 : traverse();break;
		 case 2 : insert_at_beg();break;
	     case 3: insert_at_last();break;
	     case 4: insert_at_pos();break;
	     case 5: del_at_beg();break;
	     case 6: del_at_last();break;
	     case 7: del_at_pos();break;
	     case 8: reverse();break;
	     case 9: exit(0);
		 default :printf("\nwrong choice\n");
	}


	printf("enter choice\n");
	printf("1.traverse\n2.insert at begining\n3.insert at last\n4.insert at position\n5.delete at begining\n6.delete at last\n7.delete at position\n8.reverse\n9.exit\t");
	scanf("%d",&ch);
    }
}

void traverse()
{
NODE*newheader;
newheader=header;

	if(newheader==NULL)
	{
	printf("list is empty\n");
	return;
	}

	printf("list elements are\n");
	do
	{
		 printf("%d\n",newheader->data);
		 newheader=newheader->nxt;
	} while (newheader!=header);
	show();

}

void insert_at_beg()
{
	NODE*cpt,*temp;
	if(header==NULL)
	{
	 createdoublylinklist();
	 }
	else
	{

	cpt=(NODE*)malloc(sizeof(NODE));
	printf("enter value\t");
	scanf("%d",&cpt->data);
	header->pre->nxt=cpt;
	cpt->pre=header->pre;
	header->pre=cpt;
	cpt->nxt=header;
	header=cpt;
   }
}

void insert_at_last()
{
	NODE*cpt,*newheader;
	newheader=header;
	if(newheader==NULL)
	{
    createdoublylinklist();
	}

    else
    {

	cpt=(NODE*)malloc(sizeof(NODE));
	printf("enter value\t");
	scanf("%d",&cpt->data);
    newheader->pre->nxt=cpt;
	cpt->pre=newheader->pre;
	newheader->pre=cpt;
	cpt->nxt=newheader;
  }
}


void del_at_beg()
{
     NODE*newheader;
     newheader=header;

	if(header==NULL)
	{
		printf("\nlist is empty\n");
		return;
	}
	else if(header->nxt==header)
	{
	  header=NULL;
	}
       else

	{
	 header=header->nxt;
       newheader->pre->nxt=newheader->nxt;
	header->pre=newheader->pre;
	}

}

void del_at_last()
{
   NODE*newheader,*preheader;
	newheader= header;

	if(newheader==NULL)
	{
		printf("list is empty\t");
		return;
	}
       else if(newheader->nxt==header)
	{
		header=NULL;
		return;
	}                             
    	else
	{
	   newheader->pre->pre->nxt=newheader;
	   newheader->pre=newheader->pre->pre;
	}
}

void del_at_pos()
{
	 NODE*newheader;
	 int pos,count=1,flag=1;
	 newheader=header;

	 if(newheader==NULL)
	 {
		printf("list is empty\n");
		return;
	 }

	 printf("enter position of element to be deleted");
	 scanf("%d",&pos);

     if(pos==1)
     {
       del_at_beg();
       return;
     }
     else
     {

	   do
	{
		count++;

	       if(pos==count)
		{
		      newheader->nxt=newheader->nxt->nxt;
		      newheader->nxt->pre=newheader;
		      flag=0;
	       }

		      else  newheader=newheader->nxt;

	}while(newheader!=header);
     }

      if(flag==1)
      {
	printf("\npostion not found\n");
	  }
}






void insert_at_pos()
{
	NODE*newheader,*cpt;
	newheader=header;
	int pos,count=1;
	
	printf("enter position of new element\t");
	scanf("%d",&pos);
			
	if(pos<1)
	printf("enter correct position\n");

    else if(pos==1)
    insert_at_beg();
	
    else  
      {

                do	
	             {
		             count++;
		             if(pos==count)
		                     {
		 	                    	cpt=(NODE*)malloc(sizeof(NODE));
		 	                        printf("enter element");
		 	                        scanf("%d",&cpt->data);
		 	                        newheader->nxt->pre=cpt;
	                         		cpt->pre=newheader;
			                        cpt->nxt=newheader->nxt;
			                        newheader->nxt=cpt;
                            }  
                     else 
                             		newheader=newheader->nxt; 
             	}while(newheader!=header);
       } 
}




void show()
{
    NODE*newheader;
    newheader=header;

    do
    {
    printf("\n%u\t%u\t%d\t%u",newheader,newheader->pre,newheader->data,newheader->nxt);
    newheader=newheader->nxt;
    }while(newheader!=header);

 }

void reverse()
{
	NODE*newheader;
	newheader=header;
	
	if(newheader==NULL)
	{
		printf("\nlist is empty\n");
		return;
    }
    
    else if(newheader->nxt==header)
    {
    	printf("\nelements are = %d",newheader->data);
    	return;
	}
	
	else
	{
		printf("\nreverse of list is\n");
		do 
		{
		  newheader=newheader->pre;
		  printf("%d\n",newheader->data);	
		}while(newheader->pre!=header->pre);
	}
}
