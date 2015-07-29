#include<bits/stdc++.h>
using namespace std;

struct node{
	char value;
	node* prev;
};

void push(node** top, char value)
{
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->value = value;
	temp->prev = *top;
	*top = temp;
	return;
}

void pop(node** top)
{
	node *temp = *top;
	*top = ((*top)->prev);
	free(temp);
	return;
}

int main()
{
	char x[1001];
	int siz;
	node *top=NULL;
	cin>>siz>>x;
	cout<<x;
	for (int i = 0; i < siz; ++i)
	{
		if(x[i]=='('||x[i]=='{'||x[i]=='[') 
		{
			push(&top, x[i]);
		}
		else
		{
			if(top!=NULL)
			{
				char y = (top)->value;
				if((x[i]==')'&&y=='(')||(x[i]==']'&&y=='[')||(x[i]=='}'&&y=='{')) pop(&top);
				else {
						cout<<"NO";
						return 0;
					}
			}
			else {cout<<"NO"; return 0;}
		}
	}
	if(top!=NULL) cout<<"NO";
}