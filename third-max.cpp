#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int i,1max=INT_MIN,2max=INT_MIN,3max=INT_MIN;
	for(i = 0; i < A.size(); i++)
	{
		if(A[i]>=1max){
			2max = 1max;
			3max = 2max;
			1max = A[i];
		}
		else if(A[i]>=2max){
			3max = 2max;
			2max = A[i];
		} else if(A[i]>=3max){
			3max = A[i];
		}
	}
	return 0;
}