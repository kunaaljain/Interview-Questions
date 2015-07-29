#include<bits/stdc++.h>
using namespace std;


void permute(string x, int l, int r)
{
	if(l==r) {
		cout<<x<<endl;
		return;
	}
	for(int i=l;i<=r;i++)
	{
		swap(x[l],x[i]);
		permute(x,l+1,r);
		swap(x[l],x[i]);
	}
}

int main()
{
	string x;
	cin>>x;
	permute(x,0,x.length()-1);
}