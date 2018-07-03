#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
	struct node *l,*r;
	int a;
 }NODE;
 NODE*root;
 void morris();
 void create();
 void inorder(NODE*);  
int main()
{
	int ch=1,op;
	
	while(ch==1)
	{
		printf("enter choice \n");
		printf("1.insert\t");
		scanf("%d",&op);
		switch (op)
		{
			case 1: create();break;
			case 2 :	{  
	                       morris();
	                       exit(0);
						}
	   }
	   printf("press 1 to continue\t");
	   scanf("%d",&ch);
    } 
morris();
return 0;
}

void create()
{
	NODE*parent,*p,*temp;
	temp=(NODE*)malloc(sizeof(NODE));
	printf("enter no\t");
	scanf("%d",&temp->a);
	temp->l=temp->r=NULL;
	
	if(root==NULL) {root=temp;return;}
	
	p=root;
	while(p!=NULL)
	{
		parent=p;
		if(temp->a>p->a)
		p=p->r;
		
		else p=p->l;
	}
	if(parent->a>temp->a)
	parent->l=temp;
	
	else parent->r=temp;
	
}

void morris()
{
	NODE*p=root,*temp;
	if(p==NULL)return;
	
	printf("inorder traversal \n\n");
	while(p!=NULL)
	{
		if(p->l==NULL)
		{
			printf("%d\n",p->a);
			p=p->r;
		}
		else
		{
			temp=p->l;
			
			while(temp->r!=NULL&&temp->r!=p)
	        temp=temp->r;
	        
	        if(temp->r==NULL)
	        {
	        	temp->r=p;
	        	p=p->l;
			}
			else
			{
				temp->r=NULL;
				printf("%d\n",p->a);
				p=p->r;
			}
		}
	}
}
