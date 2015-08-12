#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x,y;
	node *next;
};

void push(node **head, int x, int y)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->x = x;
	temp->y = y;
	temp->next = *head;
	*head = temp;
}

int main()
{
	node *head=NULL,*temp;

	push(&head,0,0);
	push(&head,0,2);
	push(&head,0,5);
	push(&head,0,10);
	push(&head,5,10);
	push(&head,5,5);
	temp = head;
	while(head!=NULL&&head->next!=NULL&&head->next->next!=NULL)
	{
		if(head->x==head->next->x && head->next->x==head->next->next->x)
		{
			node* temp = head->next; 
			head -> next = head->next->next;
			free(temp);
		}
		else if(head->y==head->next->y && head->next->y==head->next->next->y)
		{
			node* temp = head->next;
			head -> next = head->next->next;
			free(temp);
		}
		else head = head -> next;
	}
	while(temp!=NULL) cout<<temp->x<<" "<<temp->y<<endl, temp = temp->next;

}