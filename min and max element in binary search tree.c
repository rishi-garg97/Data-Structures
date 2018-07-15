#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
	struct node *l,*r;
	int a;
 }NODE;
 NODE*root;
 
  void create();
 void min_max();  
int main()
{
	int ch=1,op;
	
	while(ch==1)
	{
		printf("enter choice \n");
		printf("1.insert\n2.min and max\t");
		scanf("%d",&op);
		switch (op)
		{
			case 1: create();break;
			case 2 :min_max();break;
	   }
	   printf("press 1 to continue\t");
	   scanf("%d",&ch);
    } 
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
		if(temp->a>=p->a)
		p=p->r;
		
		else p=p->l;
	}
	if(parent->a>temp->a)
	parent->l=temp;
	
	else parent->r=temp;
	
}

void min_max()
{
	NODE*temp,*p=root;
	int min ,max;
	if(p==NULL)return;
	
			
			while(p->l!=NULL)
			p=p->l;
			
            min=p->a;
			
			p=root;
			while(p->r!=NULL)
			p=p->r;
		 
		    max=p->a;
	
	printf("min = %d,max = %d",min,max);
}

