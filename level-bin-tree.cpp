#include<bits/stdc++.h>
using namespace std;

struct tree
{
	int value;
	tree *l;
	tree *r;
	tree *n;
};

struct node
{
	tree *value;
	int level;
	node *next;
	
};

void push(node **head, node **tail, tree *value, int level)
{
	if(value == NULL) return;
	node *temp = (node*)malloc(sizeof(node));
	temp -> value = value;
	temp -> level = level;
	temp -> next = NULL;
	if(*tail != NULL) (*tail) -> next = temp;
	if(*head == NULL) *head = temp; // new queue
	*tail = temp;
}

void pop(node **head)
{
	cout<<(*head)->value->value<<" "<<endl;
	node *temp = *head;
	*head = temp->next;
	free(temp);
}

void traverselink(tree *root)
{
	node *head=NULL, *tail=NULL;
	push(&head,&tail,root,0);
	while(head!=NULL)
	{
		if(head->next!=NULL && head->level == head->next->level)
			head->value->n = head->next->value;
		push(&head,&tail,head->value->l,head->level+1);
		push(&head,&tail,head->value->r,head->level+1);
		pop(&head);
	}
}

tree* insert(tree **x, int val)
{
	if(*x == NULL)
	{
		tree *temp;
		temp = (tree *)malloc(sizeof(tree));
		temp->l=NULL;
		temp->r=NULL;
		temp->value=val;
		*x = temp;
		return temp;
	}
	else
	{
		if(val > ((*x)->value)) return insert( &((*x)->r), val);
		else return insert( &((*x)->l), val); 
	}
}


int main()
{
	tree *a;
	a=NULL;
	insert(&a,4);
	tree *temp = insert(&a,2);
	insert(&a,6);
	insert(&a,1);
	insert(&a,3);
	insert(&a,5);
	insert(&a,7);
	insert(&a,0);
	insert(&a,8);

	traverselink(a);
	cout<< temp->n->value;

}