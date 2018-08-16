#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node
{
	 int a;
	 struct node *p;
}NODE;

NODE*header;
void traverse(NODE*);
void insert_at_beg(NODE*);
void main()
{
	  int ch; int op;
	  NODE *ptr,*cpt;
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
			   cpt->p=NULL;
		
		   
		   printf("press 1 to continue");
		   scanf("%d",&ch);
			   	  
	   }  
	   ptr->p=NULL;
	 
	 printf("enter option\n");
	 printf("11.Traverse\n22.Insert at begining");
	 scanf("%d",&op);
	 
	 switch (op) 
	 
	 {
	 	case 11:	
        traverse(header);break;      
	    
	    
	    case 22:
	    insert_at_beg(header);break;	
        
        default: 
		printf("wrong choice");break;
       	  
	}
	  
	   getch();
        
}

void traverse(NODE*header)
{
	printf("enter values are\n");
	while(header!=NULL)
	{
		printf("\t%d",header->a);
        header=header->p;
	}
	printf("\tNULL");
	
	
}

void insert_at_beg(NODE*header)
{
	NODE *beg;
	beg=(NODE*)malloc(sizeof(NODE));
	beg->p=header;
	header=beg;
	printf("enter value");
	scanf("%d",&beg->a);
	traverse(header);
}

