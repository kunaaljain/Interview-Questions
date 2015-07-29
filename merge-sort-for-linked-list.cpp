/*
	http://www.geeksforgeeks.org/merge-sort-for-linked-list/
*/

#include<bits/stdc++.h>
using namespace std;

struct node {
	int value;
	node *next;
};

void splitsort(node *head, node **a, node **b);
node* combinesort(node *a, node *b);
void printlist(node **head);

void mergesort(node **head)
{
	if(*head == NULL || (*head) -> next == NULL) return;
	node *a,*b;
	splitsort(*head, &a, &b);
	mergesort(&a);
	mergesort(&b);
//	printlist(&a),printlist(&b);
	*head = combinesort(a, b);
//	printlist(head);
	free(a),free(b);
}

void splitsort(node *head, node **a, node **b)
{
	*a = NULL, *b = NULL;
	node *l = NULL, *r = NULL;
	int x=0;
	while(head!=NULL)
	{
		node *temp;
		temp = (node *)malloc(sizeof(node));
		temp -> next = NULL;
		temp -> value = head -> value;
		//cout<<head->value<<"X";
		head = head -> next;
		if(x==0)
		{
			if(l==NULL){ l = temp; *a = l; }
			else {l->next = temp; l = temp;}
		}
		else
		{
			if(r==NULL){ r = temp; *b = r; }
			else {r->next = temp; r = temp;}
		}
		x^=1;
	}
}

node* combinesort(node *a, node *b)
{
	node *head = NULL;
	node *root = NULL;
	while(a!=NULL&&b!=NULL)
	{
		if(a -> value > b -> value)
		{
			node *temp = (node *)malloc(sizeof(node));
			temp -> value = b -> value;
			temp -> next = NULL;
			b = b -> next;
			if( head == NULL ) head = temp, root = temp;
			else head -> next = temp, head = head -> next;
		}
		else
		{
			node *temp = (node *)malloc(sizeof(node));
			temp -> value = a -> value;
			temp -> next = NULL;
			a = a -> next;
			if( head == NULL ) head = temp, root = temp;
			else head -> next = temp, head = head -> next;
		}
	}
	while(a!=NULL)
	{
		node *temp = (node *)malloc(sizeof(node));
		temp -> value = a -> value;
		temp -> next = NULL;
		a = a -> next;
		if( head == NULL ) head = temp, root = temp;
		else head -> next = temp, head = head -> next;
	}
	while(b!=NULL)
	{
		node *temp = (node *)malloc(sizeof(node));
		temp -> value = b -> value;
		temp -> next = NULL;
		b = b -> next;
		if( head == NULL ) head = temp, root = temp;
		else head -> next = temp, head = head -> next;		
	}
	return root;
}

void insertnode(node **head, int value)
{
	node *temp,*temp1;
	temp1 = (node *)malloc(sizeof(node));
	temp = *head;
	while(temp->next!=NULL) temp = temp->next;
	temp1->value = value;
	temp->next = temp1;
	temp->next->next = NULL;
}

void makelist(node **head, int value)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->value = value;
	temp->next = NULL;
	*head = temp;
}

void printlist(node **head)
{
	node *temp;
	temp = *head;
	while(temp!=NULL) cout<<temp->value<<" ",temp=temp->next;
	cout<<"\n";
}


int main()
{
	node *head,*temp;
	makelist(&head, 0);
	insertnode(&head, 3);
	insertnode(&head, 9);
	insertnode(&head, 5);
	insertnode(&head, 1);
	insertnode(&head, 8);
	insertnode(&head, 1);
	insertnode(&head, 4);
	printlist(&head);
	mergesort(&head);
	printlist(&head);
	
}