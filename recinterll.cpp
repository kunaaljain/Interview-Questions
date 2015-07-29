#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

node* intersect(node *a, node *b)
{
	if(a==NULL||b==NULL) return NULL;
	if(a->data > b->data) return intersect(a,b->next);
	if(a->data < b->data) return intersect(a->next,b);
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=a->data;
	temp->next = intersect(a->next,b->next);
	return temp;
}

void printlist(node *a)
{
	while(a!=NULL) 
	{
		cout<<(a->data)<<" ";
		a=a->next;
	}
	cout<<endl;
}

void insert(node **a, int val)
{
	if(*a==NULL)
	{
		node *temp;
		temp = (node*)malloc(sizeof(node));
		temp->data = val;
		temp->next = NULL;
		*a = temp;
		return;
	}
	else
	{
		node *temp = *a;
		while(temp->next!=NULL) temp = temp->next;
		temp->next = (node*)malloc(sizeof(node));
		(temp->next)->data = val;
		(temp->next)->next = NULL;
		return;
	}

}

int main()
{
	node *a=NULL,*b=NULL,*c=NULL;
	insert(&a,1);
	insert(&a,2);
	insert(&a,3);
	insert(&a,4);
	insert(&a,5);

	insert(&b,0);
	insert(&b,2);
	insert(&b,4);
	printlist(a);
	printlist(b);

	c=intersect(a,b);
	printlist(c);

}