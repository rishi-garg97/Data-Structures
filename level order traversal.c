#include<stdio.h>
#include<conio.h>
#include<malloc.h>

typedef struct node
{
	struct node *l,*r;
	int a;
 }NODE;
 NODE*root;

int front=-1,rear=-1;
NODE * queue[50];
void push();
void level(NODE*);
NODE*pop();
 void create();
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
			case 2 :level(root);
   	    }
	   printf("press 1 to continue\t");
	   scanf("%d",&ch);
    }
	level(root); 
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

void level(NODE* root)
{
	if(root==NULL)return;
	NODE*p;
	
	printf("level order traversal is\n");
	push(root);
	
	while(front!=rear)
	{
	    p=pop();
	    printf("%d\n",p->a);
		if(p->l!=NULL)
		push(p->l);
		if(p->r!=NULL)
		push(p->r);
	}
}

void push(NODE*s)
{
	rear++;
	queue[rear]=s;
}
NODE*pop()
{
	front++;
	NODE*temp=queue[front];
	return temp;
}
