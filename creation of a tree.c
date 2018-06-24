#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct tree 
{
	struct tree *l;
	int a;
	struct tree *r;
};

struct tree*root;

void traverse(struct tree*);
struct tree *create(int);
int main()
{
	root=create(1);
	root->l=create(2);
	root->l->l=create(4);
	root->l->r=create(5);
	root->r=create(3);
	root->r->l=create(6);
	root->r->r=create(7);
	traverse(root);
	return 0;
	
}

struct tree *create(int t)
{
	struct tree*temp;
	temp=(struct tree*)malloc(sizeof(struct tree));
	temp->a=t;
	temp->l=NULL;
	temp->r=NULL;
	return temp;
}

void traverse(struct tree *root)
{
	if(root==NULL)
	{
	//printf("tree is empty\n");
	return ;
	}
	else
	{
	
	traverse(root->l);
	printf("%d\n",root->a);
	
	traverse(root->r);
    }
}
