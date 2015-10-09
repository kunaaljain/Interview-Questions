#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
  node* node1 = (node*)
                       malloc(sizeof(struct node));
  node1->data = data;
  node1->left = NULL;
  node1->right = NULL;
 
  return(node1);
}


int maxdiam(node* root, int *h, int *mn, int *a, int *b)
{
	if(root==NULL)
	{
		*h = 0;
		return 0;
	}
	if(root->left==NULL&&root->right==NULL)
	{
		*mn = *a = *b = root->data;
		*h = 1;
		return 1;
	}
	int lh,rh,lmn,la,lb,rmn,ra,rb;
	int ld,rd;
	ld = maxdiam(root->left,&lh,&lmn,&la,&lb);
	rd = maxdiam(root->right,&rh,&rmn,&ra,&rb);
	if(lh+rh+1 > max(ld,rd))
	{
		*a = lmn;
		*b = rmn;
		*h = 1 + max(lh,rh);
		*mn = lh > rh ? lmn : rmn;
		return lh + rh + 1;
	}
	else if(ld > rd)
	{
		*a = la; 
		*b = lb;
		*h = 1 + max(lh,rh);
		*mn = lh > rh ? lmn : rmn;
		return lh + rh + 1;
	}
	else
	{
		*a = ra;
		*b = rb;
		*h = 1 + max(lh,rh);
		*mn = lh > rh ? lmn : rmn;
		return lh + rh + 1;
	}
}

int main(int argc, char const *argv[])
{
	int h,mn,a,b;
	struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->right->right = newNode(6);
  // root->left->right->right->right = newNode(7);
  // root->left->left->left= newNode(8);
  cout<<maxdiam(root,&h,&mn,&a,&b);
  cout<<" "<<a<<" "<<b;
	return 0;
}