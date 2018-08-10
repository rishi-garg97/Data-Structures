#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node
{
	 int a;
	 struct node *p;
}NODE;

NODE*header;

void traverse();
void main()
{
	  int ch; 
	  NODE *ptr,*cpt;
	  header->a=222;
	  printf("%d",header->a);
	  ptr=(NODE*)malloc(sizeof(NODE));
	  printf("enter value");
	  scanf("%d",&ptr->a);
      header=ptr;	  
	  printf("press 1 to continue");
	  scanf("%d",&ch);
	  
	  while(ch==1)
	  {
	  
	    
		   	  cpt=(NODE*)malloc(sizeof(NODE));
			   printf("enter value");
			   scanf("%d",&cpt->a);
			   ptr->p=cpt;
			   ptr=cpt;
			   
		
		   
		   printf("press 1 to continue");
		   scanf("%d",&ch);
			   	  
	   }  
	   ptr->p=NULL;
	  traverse();      
	   getch();
}
void traverse()
{
	NODE*newheader;
	newheader=header;
	
	printf("enter values are\n");
	while(newheader!=NULL)
	{
		printf("\t%d",newheader->a);
		newheader=newheader->p;
	}
	printf("\tNULL");
}
