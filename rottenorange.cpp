#include<bits/stdc++.h>
using namespace std;

struct node{
	int i;
	int j;
	int curtime;
	node *next;
	node *prev;
	node(int i1,int j1,int time1)
	{
		next = NULL;
		prev = NULL;
		i = i1;
		j = j1;
		curtime = time1;
	}
};


node* dequeue(node **head)
{
	if(*head == NULL) return *head;
	node *temp=*head;
	(*head) = (*head) -> next;
	return temp;
}

void enqueue(node **head, node **tail, int i , int j, int t)
{
	//cout<<i<<endl;
	if(*head == NULL)
	{
		*head = new node(i,j,t);
		*tail = *head;
		return;
	}
	else
	{
		node* temp = new node(i,j,t);
		(*tail)->next=temp;
		temp->prev=*tail;
		*tail = temp;
		return;
	}
}
int main()
{
	std::vector<std::vector<int> > arr = {{0,0,1,1},
											{2,1,1,1},
											{0,1,0,1},
											{0,1,0,1}};

	node *head = NULL, *tail = NULL, *temp;
	int m = arr.size();
	int n = arr[0].size();
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(arr[i][j]==2) enqueue(&head,&tail,i,j,0);
		}
	}
	int i,j,tim=0,curtim;
	while(head!=NULL)
	{
		//cout<<i<<" "<<j<<endl;
		temp = dequeue(&head);
		i = temp-> i;
		j = temp -> j;
		curtim = temp->curtime;
		tim = max(tim, curtim);
		if(i + 1 < m && arr[i+1][j] == 1)
		{
			arr[i+1][j]=2;
			enqueue(&head,&tail,i+1,j,curtim + 1);
		}
		if(i - 1 >= 0 && arr[i-1][j] == 1)
		{
			arr[i-1][j]=2;
			enqueue(&head,&tail,i-1,j,curtim + 1);
		}
		if(j + 1 < n && arr[i][j+1] == 1)
		{
			arr[i][j+1]=2;
			enqueue(&head,&tail,i,j+1,curtim + 1);
		}
		if(j -1 >= 0 && arr[i][j-1] == 1)
		{
			arr[i][j-1]=2;
			enqueue(&head,&tail,i,j-1,curtim + 1);
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(arr[i][j]==1) 
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<tim;

}