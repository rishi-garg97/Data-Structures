#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
	 int data;
	 struct node *link;
}NODE;
NODE*header;
void reverse();
void del_val();
void del_at_last();
void del_at_beg();
void ins_at_pos();
void ins_at_last();
void ins_at_beg();
void traverse();
void create_cir_link_list();
void main()
{
create_cir_link_list();
}

void create_cir_link_list()
{
	NODE*ptr,*cpt;
	int ch,op=1;
	ptr=(NODE*)malloc(sizeof(NODE));
	header=ptr;
	printf("enter data");
	scanf("%d",&ptr->data);
	
	printf("press 1 to continue else 0");
	scanf("%d",&ch);
	
	while(ch==1)
	{
		cpt=(NODE*)malloc(sizeof(NODE));
		printf("enter data");
		scanf("%d",&cpt->data);
		ptr->link=cpt;
		cpt->link=NULL;
		ptr=cpt;
	    printf("press 1 to continue else 0");
	    scanf("%d",&ch);
	}
	ptr->link=header;
  
  while(op!=9)
  {
   printf("enter choice\n1.traverse\n2.insert at begining\n3.insert at last\n4.insert at position\n5.delete at begining\n6.delete at last\n7.delete value\n8.reverse\n9.exit");
   scanf("%d",&op);	
  
   switch(op)
   {
   	case 1 : traverse();break;
   	case 2 : ins_at_beg();break;
	case 3 :  ins_at_last();break;
    case 4: ins_at_pos();break;
    case 5 :del_at_beg();break;
    case 6 :del_at_last();break;
    case 7: del_val();break;
    case 8:reverse();break;
	case 9: exit(0);break;
	default : break;    
   }
 
  }
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
	while(header!=newheader->link)
	{
		printf("%d\n",newheader->data);
		newheader=newheader->link;
	}
	printf("%d",newheader->data);
}

void ins_at_beg()
{
	NODE*ptr,*newheader,*temp;
	newheader=header;
	
	if(header==NULL)
	{
	create_cir_link_list();
	return;
    }
	ptr=(NODE*)malloc(sizeof(NODE));
	printf("\nenter element\t");
	scanf("%d",&ptr->data);
	
	
	if(header->link==header)
	{
	ptr->link=header;
    header->link=ptr;
	header=ptr;		
	}
	
	else
	{
          	while(newheader->link!=header)
                 {
	               newheader=newheader->link;  
                	 temp=newheader;
	             }
           temp->link=ptr;
           ptr->link=header;
           header=ptr;
    }
}

void ins_at_last()
{
	NODE*newheader,*temp,*ptr;
	newheader=header;
	
	
	ptr=(NODE*)malloc(sizeof(NODE));
	printf("\nenter data");
	scanf("%d",&ptr->data);
     
     if(header==NULL)
     printf("empty list");
     
     else if(header->link==header)
     header->link=ptr;
     
     else
  {
	 
	while(newheader->link!=header)
	{
		newheader=newheader->link;
	    temp=newheader;
	}
  }
  	temp->link=ptr;
    ptr->link=header;
}

void ins_at_pos()
{
	int count=1,pos;
	NODE*newheader,*ptr;
	newheader=header;
	ptr=(NODE*)malloc(sizeof(NODE));
	printf("enter position after element is to attached");
	scanf("%d",&pos);
	
	printf("\nenter data");
	scanf("%d",&ptr->data);
	
	if(newheader==NULL)
	printf("empty list");
	
	else if(newheader->link==header&&pos==count)
		       {
			       newheader->link=ptr;
		           ptr->link=header;
			   }
	
	else
	{
	     while(newheader->link!=header||pos==count)
	      {
	      	
		       if(newheader->link==header&&pos==count)
		       {
			       newheader->link=ptr;
		           ptr->link=header;
		       
			   }
	            else if(pos==count)
		       {
		           ptr->link=newheader->link;
	               newheader->link=ptr;
	               return;
	           }
		       else 
		       {
		           newheader=newheader->link;
		           count++;	
	          }
	         
	        }
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

        else if(newheader->link==header)
        {
        	header=NULL;
		}
         
		else    
			{
            	while(newheader->link!=header)
                  newheader=newheader->link;
				  	
                	header=header->link;
                 	newheader->link=header;
            }
	
}

void del_at_last()
{
	NODE*newheader;
	newheader=header;
	
     if(header==NULL)
    {
	  printf("\nlist is empty\n");  
      return;
    }

    else if(newheader->link==header)
     header=NULL;
	
    else    
	{
	   while(newheader->link!=header)
	   {
	   	    if(newheader->link->link==header)
            {
            	newheader->link=header;
			}
			else newheader=newheader->link;
	   } 
    } 
}


void del_val()
{
	NODE *newheader,*temp;
       int flag=1,val;
       newheader=header;

       if(header==NULL)
       printf("empty list");
       
	   printf("enter value to be deleted");
       scanf("%d",&val);

       if(newheader->data==val)
	{   flag=0;
	   newheader=newheader->link;
	   header=newheader;
	}
       else
	{
	   do
	      { 
		            if(newheader->data==val)
		              {
                  		  flag=0;
	                 	  newheader=newheader->link;
	                 	  temp->link=newheader;
		            }
	             	else
               		  {  
					      temp=newheader;
		                  newheader=newheader->link;
                       }
        }while(newheader->link!=header);
	 }

	if(flag==1)
	printf("element not in the list");
}




void reverse()
{
     NODE*cur,*pre=NULL,*nxt;
     cur=header;
	if(header==NULL)
	{
	printf("no element in the list");
	return ;
	}
	if(header->link==header)
	{
	 printf("only one element in list = %d",header->data);
	    return ;
	 }

    else
    {
	   do
	   {
		nxt=cur->link;
		cur->link=pre;
		pre=cur;
		cur=nxt;
	   }while(cur!=header);
	   header=pre;

   }
traverse();
}

