#include<bits/stdc++.h>
using namespace std;

struct node{
	int value;
	node *next;
};

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

void reverselist(node **head)
{
	node *prev,*cur,*nex;
	cur = *head;
	prev = NULL;
	while(cur!=NULL)
	{
		nex = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nex;
	}
	*head = prev;
}

int main()
{
	node *head,*temp;
	makelist(&head, 0);
	insertnode(&head, 1);
	insertnode(&head, 2);
	printlist(&head);
	reverselist(&head);
	printlist(&head);
	reverselist(&head);
	printlist(&head);
}