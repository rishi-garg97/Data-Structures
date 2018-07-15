#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

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
 NODE*top1();
 void create();
 void postorder();  
int main()
{
	int ch=1,op;
	
	while(ch==1)
	{
		printf("enter choice \n");
		printf("1.insert\n2.postorder traverse\t");
		scanf("%d",&op);
		switch (op)
		{
			case 1: create();break;
			case 2 :	{  
                           postorder();
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

void postorder()
{
    if (root == NULL)
        return;
     
    do
    {

        while (root)
        {
            if (root->r)
                push(root->r);
            push(root);
           
		   root = root->l;
        }
 
      root = pop();
 
       if (root->r && top1() == root->r)
        {
            pop();  
            push(root);
            root = root->r;  
        }
        else 
		        {
            printf("%d ", root->a);
            root = NULL;
        }
    } while (top!=-1);
}

void push(NODE*p)
{
	a[++top]=p;
}
NODE*top1()
{
	NODE*temp=a[top];
	return temp;
}

NODE*pop()
{
	NODE*temp=a[top];
	top--;
	return temp;
}

