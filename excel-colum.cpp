#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x,i=0;
	char y[100];
	cin>>x;
	while(x!=0)
	{
		if(x%26==0)
		{
			y[i++]='Z';
			x = x/26;
			x-=1;
		}
		else
		{
			y[i++] = (char)(x%26 + 'A' - 1);
			x = x/26;
		}
	}
	y[i]='\0';
	for(i = strlen(y) - 1; i>=0; i--) cout<<y[i];

}