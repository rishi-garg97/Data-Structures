#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct tree 
{
	struct tree *l,*r;
	int a;
} TREE;
TREE *root,*head;



 TREE*a[20];
 int top=-1;
void push(TREE*);
TREE*pop();
TREE*find(TREE*,int);
void inorder(TREE*);
void insert();
TREE*create();
int main()
{

	int ch =1;

	while(ch==1) {
		insert();
		printf("enter choice \t");
		scanf("%d",&ch);
	}
	printf("inorder traversal \n\n");
	inorder(head);
	return 0;
}


void insert() {
	TREE*newnode;

	if(root==NULL) {
		newnode= create();
		head=root=newnode;
	}

	else {
		newnode=create();
		root=head;
		while(1) {
			if(root->a>newnode->a) {
				if(root->l==NULL) {
					root->l=newnode;
					break;
				}
				root=root->l;
			}
			if(root->a<newnode->a) {
				if(root->r==NULL) {
					root->r=newnode;
					break;
				}
				root=root->r;
			}
		}
	}
}
TREE *create() 
{
	TREE*temp;
	printf("enter value\t");
	temp=(TREE*)malloc(sizeof(TREE));
	scanf("%d",&temp->a);
	temp->l=temp->r=NULL;
	return temp;
}


void inorder(TREE*p)
{
  int a;
  TREE*temp,*q;
	if(p==NULL)
		return;

   printf("enter value whose in successor has to be find\t");
   scanf("%d",&a);
    temp=find(head,a);
    
    if(temp->r!=NULL)
    {
	   temp=temp->r;
	   while(temp->l!=NULL)
	   temp=temp->l;
	   printf("insuccessor = %d",temp->a);
    }
    else if(p==temp)
     printf("doenot have inorder successor");
     
     else
     {
	while(p!=temp)
	{
		if(p->a>temp->a)
		{
			q=p;
			    p=p->l;
		    }
		    else p=p->r;
		}
		printf("inorder successor = %d",q->a);
	}

}




TREE* find(TREE*p,int n)
{

	if(p==NULL) 
	return NULL;
	
		while(1)
		{
			
			while(p->l!=NULL)
			{
				push(p);
				p=p->l;
			}
			while(p->r==NULL)
			{
				if(p->a==n)
				return p;
				
				if(top!=-1)
				p=pop();
				
				else return NULL;
			}
		if(p->a==n)
		return p;
				
		p=p->r;	
		}
		
	
}

void push(TREE*q)
{
	a[++top]=q;
}

TREE*pop()
{
	TREE*temp=a[top];
	top--;
	return temp;
}


