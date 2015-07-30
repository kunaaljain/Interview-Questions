#include<bits/stdc++.h>
using namespace std;

struct tree
{
	int val;
	tree *l;
	tree *r;
	
};

struct node
{
	tree *val;
	node *prev;
};


void push(node **top, tree* val)
{
	if(val==NULL) return;
	cout<<val->val<<" ";
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->val = val;
	temp->prev = *top;
	*top = temp;
	return;
}

void pop(node **top)
{
	node *temp = *top;
	*top = (*top)->prev;
	free(temp);
	return;
}

void spiralbfs(tree *x)
{
	node *a,*b;
	a=NULL,b=NULL;
	push(&a,x);
	while(a!=NULL||b!=NULL)
	{
		while(a!=NULL)
		{
			push(&b,a->val->l);
			push(&b,a->val->r);
			pop(&a);
		}
		while(b!=NULL)
		{
			push(&a,b->val->r);
			push(&a,b->val->l);
			pop(&b);
		}
	}
}

void insert(tree **x, int val)
{
	if(*x == NULL)
	{
		tree *temp;
		temp = (tree *)malloc(sizeof(tree));
		temp->l=NULL;
		temp->r=NULL;
		temp->val=val;
		*x = temp;
	}
	else
	{
		if(val > ((*x)->val)) insert( &((*x)->r), val);
		else insert( &((*x)->l), val); 
	}
}

int main()
{
	tree *a;
	a=NULL;
	insert(&a,4);
	insert(&a,2);
	insert(&a,6);
	insert(&a,1);
	insert(&a,3);
	insert(&a,5);
	insert(&a,7);
	insert(&a,0);
	insert(&a,8);


	spiralbfs(a);

}