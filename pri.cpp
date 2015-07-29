#include<bits/stdc++.h>
using namespace std;

void intrepret(char *dig, char *arr, int start, int len)
{
	if(start>=strlen(arr)) cout<<dig<<endl;
	else
	{
		dig[len] = (char)(arr[start] - '0' - 1 + 'a');
		dig[len + 1] = '\0';
		intrepret(dig, arr, start + 1, len + 1);
		if(!arr[start + 1]) return;
		if(((arr[start] - '0')*10 + arr[start+1]-'0') <= 26)
		{
			dig[len] = (char)(((arr[start] - '0')*10 + arr[start+1]-'0') - 1 + 'a');
			dig[len + 1] = '\0';
			intrepret(dig,arr, start + 2,len + 1);
		}
	}
}

int main()
{
	char dig[100]="\0";
	char arr[100]="1221";
	intrepret(dig,arr,0,0);
}