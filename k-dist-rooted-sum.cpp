#include<bits/stdc++.h>
using namespace std;

int value[20];
std::vector<int> edge[20];

struct node
{
	int value;
	node* left;
	node* right;
	node(int val){
		value = val;
		left = right = NULL;
	}
};

void convertgraph(node *root, int i)
{
	value[i]=root->value;
	if(root->left!=NULL)
	{
		edge[i].push_back(2*i);
		edge[2*i].push_back(i);
		convertgraph(root->left,2*i);
	}
	if(root->right!=NULL)
	{
		edge[i].push_back(2*i + 1);
		edge[2*i + 1].push_back(i);
		convertgraph(root->right,2*i + 1);
	}
}

void print(int parent, int i,int k)
{
	if(k==0) { cout<<value[i]; return; }
	for(int j = 0 ;j <edge[i].size(); j++)
	{
		if(edge[i][j]!=parent) print(i,edge[i][j],k-1);
	}
}

int find(int parent, int i, int k)
{
	if(value[i]==k) return i;
	for(int j = 0 ;j <edge[i].size(); j++)
	{
		if(edge[i][j]!=parent){ int x = find(i,edge[i][j],k);
		if( x > 0 ) return x;}
	}
	return 0;
}

int main()
{
	node *head = new node(1);
	head->left = new node(2);
	head->right = new node(3);
	head -> left -> left = new node(4);
	head -> left -> right = new node(5);
	head -> right -> left = new node(6);
	head -> right -> right = new node(7);
	convertgraph(head, 1);
	int x = find(0,1,1);
	print(0,x,2);
}