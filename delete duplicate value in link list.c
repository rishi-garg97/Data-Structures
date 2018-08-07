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
void traverse();
void del_dup_val();
int main()
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
	 printf("11.Traverse\n22.delete duplicate value\n33.exit\t");
	 scanf("%d",&op);
	 
	 switch (op) 
	 
	 {
	 	case 11:	
        traverse();break;      
	    
	    case 22: 
   		del_dup_val();break;
        
		case 33:  
        exit(0);
			
		default:
		printf("wrong choice");
	}
	  
	   getch();
   return 0;     
}

void traverse()
{
	printf("enter values are\n");
	while(header!=NULL)
	{
		printf("\t%d",header->a);
        header=header->p;
	}
	printf("\tNULL");


}

void del_dup_val()
{  NODE*newheader1,*newheader;
    newheader=header;
    

	while(newheader!=NULL&&newheader->p!=NULL)
    {
        newheader1=newheader;
        
	   while(newheader1->p!=NULL)
	 {
    	if(newheader->a==newheader1->p->a)
            {
	         newheader1->p=newheader1->p->p;
            }
       else 
      newheader1=newheader1->p;
    }
    newheader=newheader->p;

    }
    
    traverse();
}


