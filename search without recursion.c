#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct tree {
	struct tree *l,*r;
	int a;
} TREE;
TREE *root,*head;
void search();
void insert();
TREE*create();
int t;
int main() {
bool b;
	int ch =1;

	while(ch==1) {
		insert();
		printf("press 1 to insert nd 2 for searching \t");
		scanf("%d",&ch);
	}
   search();
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


void search() {
	int t;
	TREE*p=root;
	printf("enter value to be searched in tree \t");
	scanf("%d",&t);

	if(p==NULL)
   printf("value not found");

      
	else 
	{
    
      while(p!=NULL)
       {
    	if(t==p->a)
        	{
    		printf(value found");
    		return;
	     	}
    	
		else if(t>p->a)
    	   p=p->r;
    	 
		else p->l;
    	}
	}
	printf("no not found");

}
