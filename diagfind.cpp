#include<bits/stdc++.h>
using namespace std;

char mat[101][101];

void find(int i, int j, int m, int n, char x[])
{
	if(i<0||i>=m||j<0||j>=n) return;
	else
	{
		if(mat[i][j] != x[0]) return;
		if(mat[i][j] == x[0] && strlen(x)==1) {cout<<"YES"; return;}
		char temp = mat[i][j];
		mat[i][j] = '*';
		find(i+1,j-1,m,n, x + 1);
		find(i-1,j+1,m,n, x + 1);
		find(i+1,j+1,m,n, x + 1);
		find(i-1,j-1,m,n, x + 1);
		find(i,j+1,m,n, x + 1);
		find(i,j-1,m,n, x + 1);
		find(i-1,j,m,n, x + 1);
		find(i+1,j,m,n, x + 1);
		mat[i][j] = temp;
	}
}

int main(int argc, char const *argv[])
{
	int m,n;
	int i,j;
	cin>>m>>n;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			cin>>mat[i][j];

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			cout<<mat[i][j];

	cout<<endl;
	char y[]="icrosoft";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(mat[i][j]=='m')
			{
				find(i+1,j-1,m,n, y);
				find(i-1,j+1,m,n, y);
				find(i+1,j+1,m,n, y);
				find(i-1,j-1,m,n, y);
				find(i,j+1,m,n, y);
				find(i,j-1,m,n, y);
				find(i-1,j,m,n, y);
				find(i+1,j,m,n, y);
			}
		}
	}
	return 0;
}