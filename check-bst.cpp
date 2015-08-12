#include<bits/stdc++.h>
using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
	node(int val) {left = right= NULL; value = val;}
};

bool checkbst(node* root,int& ma, int& mi)
{
	if(root==NULL) return true;
	int ma1=INT_MIN,mi1=INT_MAX,ma2=INT_MIN,mi2=INT_MAX;
	bool x = checkbst(root->left,ma1,mi1);
	bool y = checkbst(root->right,ma2,mi2);
	if(x&&y)
	{
		if(ma1<root->value&&mi2>root->value)
		{
			ma = max(ma1,ma2);
			ma = max(ma,root->value);
			mi = min(mi1,mi2);
			mi = min(mi,root->value);
			return true;
		}
	}
	return false;
}

int main()
{
	int ma=INT_MIN,mi=INT_MAX;
	node* root = new node(10);
	root->left = new node(5);
	root->right = new node(15);
	root->left->left = new node(1);
	root->left->right = new node(6);
	cout<<checkbst(root,ma,mi);
}