#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int sum=0;
typedef struct node
{
	struct node *l,*r;
	int a;
 }NODE;
 NODE*root;
 NODE*a[20];
 int top=-1;
 void push(NODE*);
 NODE* pop();
 void create();
 void inorder();  
int main()
{
	int ch=1,op;
	
	while(ch==1)
	{
		printf("enter choice \n");
		printf("1.insert\n2.inorder traverse\t");
		scanf("%d",&op);
		switch (op)
		{
			case 1: create();break;
			case 2 :	{  
                           inorder();
                           printf("sum=%d",sum);
   	                       exit(0);
						}
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

void inorder()
{
	NODE*temp,*p=root;
	if(p==NULL)return;
	
		while(1)
		{
			
			while(p->l!=NULL)
			{
				push(p);
				p=p->l;
			}
			while(p->r==NULL)
			{
				sum=sum+p->a;
				printf("%d\n",p->a);
				if(top!=-1)
				p=pop();
				
				else return;
			}
			sum=sum+p->a;
		printf("%d\n",p->a);
		p=p->r;	
		}
		
	
}

void push(NODE*p)
{
	a[++top]=p;
}

NODE*pop()
{
	NODE*temp=a[top];
	top--;
	return temp;
}

