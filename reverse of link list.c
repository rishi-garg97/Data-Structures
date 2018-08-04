#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	 int a;
	 struct node *p;
}NODE;

NODE*header;
void traverse(NODE*);
void reverse(NODE*);
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
	 printf("11.Traverse\n22.reverse\n33.exit\t");
	 scanf("%d",&op);
	 
	 switch (op) 
	 
	 {
	 	case 11:	
        traverse(header);break;      
	    
	    case 22: 
		reverse(header);break;
        
		case 33:  
        exit(0);
			
		default:
		printf("wrong choice");
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

void reverse(NODE*header)
{
     NODE*cur,*pre=NULL,*nxt;
     cur=header;
	if(header==NULL)
	{
	printf("no element in the list");
	return ;
   }
	if(header->p==NULL)
   {
	 printf("only one element in list = %d",header->a);
	    return ;
   }

    else
    {
	   while(cur!=NULL)
	   {
	   	nxt=cur->p;
	   	cur->p=pre;
	   	pre=cur;
	   	cur=nxt;
	   }
	   header=pre;
	
   }
traverse(header);	
}

