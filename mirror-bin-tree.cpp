#include<bits/stdc++.h>
using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
	node(int val)
	{
		left = right = NULL;
		value = val;
	}
};

node* mirror(node *source)
{
	if(source==NULL) return NULL;
	node *root=(node*)malloc(sizeof(node));
	root->value = source ->value;
	root->left = mirror(source->right);
	root->right = mirror(source->left);
	return root;
}

void printlevelwise(node *root)
{
	queue< pair<node*,int> > x;
	x.push(make_pair(root,0));
	int curlevel = 0;
	while(!x.empty())
	{
		if(x.front().second>curlevel) cout<<endl,curlevel = x.front().second;
		cout<<x.front().first->value<<" ";
		if(x.front().first->left) x.push(make_pair(x.front().first->left,curlevel+1));
		if(x.front().first->right) x.push(make_pair(x.front().first->right,curlevel+1));
		x.pop();
	}
	cout<<endl;
}



int main(int argc, char const *argv[])
{
	node *tree1,*tree2;
	tree1 = new node(1);
	tree1->left = new node(2);
	tree1->right = new node(3);
	tree1->left->left = new node(4);
	tree1->left->right = new node(5);
	tree1->right->left = new node(6);
	printlevelwise(tree1);
	tree2 = mirror(tree1);
	printlevelwise(tree2);
	return 0;
}