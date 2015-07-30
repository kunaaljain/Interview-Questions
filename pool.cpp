/*

	Given a matrix which consists of 1’s and 0’s, a pool is defined as a collection of 0’s completely surrounded by 1’s. Example,

	4 13
		
	1 1 1 1 1 1 0 0 0 0 1 1 1

	1 1 1 0 0 1 1 0 0 1 1 1 1

	1 1 0 0 0 1 1 1 1 1 1 1 1

	1 1 1 1 1 1 1 1 1 0 0 0 0

	This matrix contains only one pool since only one group of 0’s is completely surrounded with 1’s

	Find the number of pools in a given matrix

*/

#include<bits/stdc++.h>
using namespace std;

int mat[101][101];

void recfill(int r, int c, int n, int m)
{
	if(r<0||r>=n||c<0||c>=m) return;
	if(mat[r][c]!=0) return;
	mat[r][c]=1;
	recfill(r,c+1,n,m);
	recfill(r,c-1,n,m);
	recfill(r+1,c,n,m);
	recfill(r-1,c,n,m);
}

int main()
{
	freopen("in.txt","r",stdin);
	int r,c,sol=10;
	cin>>r>>c;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin>>mat[i][j];
		}
	}
	for (int i = 0; i < r; ++i)
	{
		if(mat[i][0]==0) recfill(i,0,r,c);
		if(mat[i][c-1]==0) recfill(i,c-1,r,c);
	}
	for (int i = 0; i < c; ++i)
	{
		if(mat[0][i]==0) recfill(0,i,r,c);
		if(mat[c-1][i]==0) recfill(c-1,i,r,c);
	}
	for (int i = 1; i < r-1; ++i)
	{
		for (int j = 1; j < c-1; ++j)
		{
			if(mat[i][j]==0)
			{
				if(mat[i][j+1]==1&&mat[i][j-1]==1&&mat[i-1][j]==1&&mat[i+1][j]==1) mat[i][j]=sol++;
				else
				{
					mat[i][j] = (mat[i-1][j]!=0?mat[i-1][j]:mat[i][j]);
					mat[i][j] = (mat[i-1][j]!=0?mat[i+1][j]:mat[i][j]);
					mat[i][j] = (mat[i][j-1]!=0?mat[i][j-1]:mat[i][j]);
					mat[i][j] = (mat[i][j+1]!=0?mat[i][j+1]:mat[i][j]);
				}
			}
		}
	}
	cout<<sol-10<<endl;
}