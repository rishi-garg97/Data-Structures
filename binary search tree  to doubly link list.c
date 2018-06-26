#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct tree {
	struct tree *l,*r;
	int a;
} TREE;
TREE *root,*head;

typedef struct doub
{
	struct doub *ld,*rd;
	int data;
}DLL;
DLL *header;

void push(TREE*);
void printdll(DLL*);

void inorder(TREE*);
void insert();
TREE*create();
int main() {

	int ch =1;

	while(ch==1) {
		insert();
		printf("enter choice \t");
		scanf("%d",&ch);
	}
	printf("inorder traversal \n\n");
	inorder(head);
	printdll(header);
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
TREE *create() {
	TREE*temp;
	printf("enter value\t");
	temp=(TREE*)malloc(sizeof(TREE));
	scanf("%d",&temp->a);
	temp->l=temp->r=NULL;
	return temp;
}


void inorder(TREE*p) {
	if(p==NULL)
		return;

	else {

		inorder(p->l);
		push(p);
		printf("%d\n",p->a);
		inorder(p->r);
	}

}

void push(TREE*d)
{
	DLL*newheader=header,*ptr;
	
	ptr=(DLL*)malloc(sizeof(DLL));
	ptr->data=d->a;
	ptr->ld=ptr->rd=NULL;
	
	
	if(header==NULL)
	  header=ptr;
	  
	  else
	  {
	  	while(newheader->rd!=NULL)
	  	newheader=newheader->rd;
	  	
	  	newheader->rd=ptr;
	  	ptr->ld=newheader;
	  }
}
void printdll(DLL*p)
{
printf("element of DLL are\n");
	do
	{
		printf("%d\n",p->data);
		p=p->rd;
	}
	while(p!=NULL);

}
