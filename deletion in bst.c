#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
	struct node *l,*r;
	int a;
 }NODE;
 
 NODE*root;
 
 void inorder(NODE*);
 void create();
 void del();  
int main()
{
	int ch=1,op;
	

	while(ch==1)
	{
		printf("enter choice \n");
		printf("1.insert\n2.deletion\t");
		scanf("%d",&op);
		switch (op)
		{
			case 1: create();break;
			case 2 :	{  
			   del();
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

void del()
{
	NODE*p=root,*parent=root,*psucc;
	int t;
	inorder(root);
	printf("enter no to be deleted\t");
	scanf("%d",&t);

	if(p==NULL)
	{
		printf("tree is empty");
		return;
	}
	while(p!=NULL)
	{
		if(p->a==t)
		break;
		else
		{
			parent =p;
			if(p->a>t)p=p->l;
		else p=p->r;
		}
	}
	if(p==NULL)
	{
		printf("not found");
		return;
	}

	//no child
	else if(p->l==NULL&&p->r==NULL)
	{
	   if(parent->r==NULL&&parent->l==NULL)
	       { root=NULL;return; }

	   if(parent->r==p)
		 parent->r=NULL;

		 else parent->l=NULL;
		 free(p);
	}

	//one child
	else if(p->l==NULL&&p->r!=NULL)
	{
	if(parent==p )
	root=p->r;
	    else if(parent->l==p)
		 parent->l=p->r;

		 else parent->r=p->r;
		 free(p);
	}

       else if(p->r==NULL&&p->l!=NULL)
	{
	if(parent==p)
	root=p->l;

	    else  if(parent->l==p)
		 parent->l=p->l;

		 else parent->r=p->l;
		 free(p);
	}

	//both child
	else
	//(p->l!=NULL&&p->r!=NULL)
	{
		parent=p;
		psucc=p->r;

		while(psucc->l!=NULL)
		{
			parent=psucc;
			psucc=psucc->l;
		}
		p->a=psucc->a;
		p=psucc;

		if(parent->l==psucc)
		 parent->l=psucc->r;

		 else parent->r=psucc->r;
		 free(p);

	}
	printf("inorder traverse\t");
inorder(root);
}
void inorder(NODE*p)
{
    if(p==NULL)return;
	else
	{
		inorder(p->l);
		printf("%d",p->a);
		inorder(p->r);
		}
}
