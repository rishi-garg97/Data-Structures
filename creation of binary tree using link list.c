#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
typedef struct tree
{
	struct tree *l,*r;
	int a;
}TREE;
typedef struct node
{
	TREE*lt;
	struct node*ll;
}NODE;
NODE*headl;
TREE *headt;
TREE*pop();
void inorder(TREE*);
void insert();
void del();
void push(TREE*);
void creation();
int main()
{

   int op=1;

	printf("\nenter choice\n1.creation\n2.exit\t");
	scanf("%d",&op);

      switch(op)
	{
		case 1: creation();break;
		default :exit(0);
	}

      printf("inorder traversal is\n");
      inorder(headt);


  return 0;
}
void inorder(TREE*p) {
	if(p==NULL)
		return;

	else {

		inorder(p->l);
		printf("%d\n",p->a);
		inorder(p->r);
	}
}


void creation()
{
	int l,m,i,j,k;

	printf("\nenter no of level of tree\t");
	scanf("%d",&l);

	if(l==0)
	{  printf("tree is empty");return; }
	for(i=0,k=1;i<l;i++,k++)
	{
	m=pow(2,i);
	printf("\nenter value in level -: %d\t",k);
		for(j=m;j>=1;j--)
		insert();
	}
}
void insert()
{
	TREE*ptr,*temp;
	ptr=(TREE*)malloc(sizeof(TREE));
	scanf("%d",&ptr->a);
	ptr->l=ptr->r=NULL;

	if(headt==NULL)
	{
	  headt=ptr;
	  push(ptr);
	}

	else
	{
		temp=pop();
		if(temp->l==NULL)
			temp->l=ptr;
		else
		{
		temp->r=ptr;
		del();
		}
		push(ptr);
	}
}

TREE* pop()
{
	return headl->lt;
}
void push(TREE *link)
{
	NODE*ptr,*cpt=headl;
	ptr=(NODE*)malloc(sizeof(NODE));
	ptr->lt=link;
	ptr->ll=NULL;

	if(headl==NULL)headl=ptr;
	else
	{
		while(cpt->ll!=NULL)
		cpt=cpt->ll;
		cpt->ll=ptr;
	}
}
void del()
{
	headl=headl->ll;
}
