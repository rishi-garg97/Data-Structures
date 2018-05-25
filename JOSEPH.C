#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	struct node *p;
	char name[100];
}NODE;

NODE*header;
void del();
void traverse();
int main()
{
	NODE*ptr,*cpt,name[100];
	int ch,ch1=1,op=1;
	ptr=(NODE*)malloc(sizeof(NODE));
    header=ptr;
	printf("enter name\t");
	scanf("%s",ptr->name);
	printf("press 1 to continue else 0");
	scanf("%d",&ch);

	while(ch==1)
	{
		cpt=(NODE*)malloc(sizeof(NODE));
		printf("enter name\t");
		scanf("%s",cpt->name);
		ptr->p=cpt;
		cpt->p=NULL;
		ptr=cpt;
	    printf("press 1 to continue else 0");
	    scanf("%d",&ch);
	}
	ptr->p=header;

printf("\n\n");
   traverse();

	while(ch1==1)
	{
	   printf("\nenter choice\n");
	    printf("1.delete\n2.exit\t");
	    scanf("%d",&op);

		switch(op)
		{
			case 1: del();break;
			default : exit(0);

		}

		printf("to continue press 1");
		scanf("%d",&ch);
	}
	 return 0;
}


void del()
{
	NODE*ptr=header,*pptr=header;
	char name1[100];
	int i,n,found=1;
	char nam[100];

	fflush(stdin);
	printf("enter name \t");
	gets(nam);

	do
	{
		if(!strcmp(ptr->name,nam))
		{
			found=0;
			break;
		}
		else
		{
			pptr=ptr;
		  ptr=ptr->p;
	    }
	}while(ptr!=header);

	if(found==1)
	{
	  printf("name not found\n");
	return;
	}
	else
	{
		printf("enter no\t");
		scanf("%d",&n);


			while(pptr->p!=pptr)
			 {
				for(i=1;i<n;i++)
				 {
				       pptr=ptr;
				       ptr=ptr->p;
				 }
				 if(pptr==header)
				 {
				    strcpy(pptr->name,ptr->name);
				 	pptr->p=ptr->p;
					 ptr=ptr->p;
				 }
				 else
				 {
				 	pptr->p=ptr->p;
				 	ptr=ptr->p;
				 }
		         		 
   		     }

      }
      if(pptr->p==pptr)
   printf("element = %s",pptr->name);
}
void traverse()
{
	NODE*newheader;
	newheader=header;
	if(header==NULL)
	{
		printf("\nlist is empty\n");
		return;
	}
	printf("enter elements are\n\n");
	  do
	{
		printf("%s\n",newheader->name);
		newheader=newheader->p;
	}while(header!=newheader);

}



