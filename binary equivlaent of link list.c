#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	 int a;
	 struct node *p;
}NODE;

NODE*header;
void traverse();
void binary_eq();
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
	 printf("11.Traverse\n22.binary equivalent\n33.exit\t");
	 scanf("%d",&op);
	 
	 switch (op) 
	 
	 {
	 	case 11:	
        traverse();break;      
	    
	    case 22: 
		binary_eq();break;
        
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

void binary_eq()
{
	int eq=0,p,n=0,flag=0;
     NODE*cur,*pre=NULL,*nxt;
     cur=header;

	if(header==NULL)
	{
      	printf("no element in the list");
        	return ;
   }
   
   else if(header->p==NULL)
   {
   	printf("binary eq is \n");
     	if(header->a==0)
   	      {printf("%d",0);return;}
   	    
		else {printf("%d",1);return;}
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
  
  while(pre!=NULL)
  {
  	if(pre->a==0||pre->a==1)
  	{
	 flag=1;
      p=pre->a*pow(2,n); 	
	  eq=eq+p;
	  n++;
	  pre=pre->p;
    }
    
    else {printf("not a binary no");break;}

   }
   
    if(flag==1)
   {	printf("binary eq is \n");
    printf("%d",eq);  	
   }
}

