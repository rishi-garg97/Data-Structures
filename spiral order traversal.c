#include<stdio.h>
#include<conio.h>
#include<malloc.h>

typedef struct node
{
	struct node *l,*r;
	int a;
 }NODE;
 NODE*root;
 void create();

struct stack
{
	struct node *st[40];
	int top;
}s[2];

void push(int ,NODE*);
NODE*pop(int);
void spiral(NODE*);

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
			case 2 :spiral(root);
   	    }
	   printf("press 1 to continue\t");
	   scanf("%d",&ch);
    }
	spiral(root); 
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
void spiral(NODE*root)
{
	NODE*p;
	if(root==NULL)return;

s[1].top=-1;
s[2].top=-1;

printf("elements are\n");	
	push(1,root);
	
	while(s[1].top!=-1||s[2].top!=-1)
	{
		while(s[1].top!=-1)
		{
			p=pop(1);
			if(p->l!=NULL)
			push(2,p->l);
			
			if(p->r!=NULL)
			push(2,p->r);
			
			printf("%d\n",p->a);
		}
		while(s[2].top!=-1)
		{
			p=pop(2);
			if(p->r!=NULL)
			push(1,p->r);
			
			if(p->l!=NULL)
			push(1,p->l);
			
			printf("%d\n",p->a);
		}
	}	
}



void push(int n,NODE* p)
{
	if(n==1)
	{
		s[1].top++;
		s[1].st[s[1].top]=p;
	}
	
	if(n==2)
	{
		s[2].top++;
		s[2].st[s[2].top]=p;
	
	}
}
NODE* pop(int n)
{
	NODE*temp;
	
	if(n==1)
	{
		temp=s[1].st[s[1].top];
		s[1].top--;
	}
	if(n==2)
	{
		temp=s[2].st[s[2].top];
		s[2].top--;
	}
	return temp;
}
