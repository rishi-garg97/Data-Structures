#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct tree {
	struct tree *l,*r;
	int a;
} TREE;
TREE *root,*head;
void inorder(TREE*);
void preorder(TREE*);
void postorder(TREE*);
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
	printf("preorder traversal \n\n");
	preorder(head);
	printf("postorder traversal \n\n");
	postorder(head);
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
			printf("%d\n",p->a);
		inorder(p->r);
	}

}
void postorder(TREE*p) {
	if(p==NULL)
		return;

	else {

		postorder(p->l);
		postorder(p->r);
		printf("%d\n",p->a);
	}

}
void preorder(TREE*p) {
	if(p==NULL)
		return;

	else {

		printf("%d\n",p->a);
		preorder(p->l);
		preorder(p->r);
	}

}
