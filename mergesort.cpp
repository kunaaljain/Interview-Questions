#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int a, int b, int c, int d);

void divide(int arr[], int a, int b)
{
	if(a==b) return;
	divide(arr,a,(a+b)/2);
	divide(arr,(a+b)/2 +1,b);
	merge(arr, a, (a+b)/2, (a+b)/2 + 1, b);
}

void merge(int arr[], int a, int b, int c, int d)
{
	int *temp,i = a, j = c, k = 0;
	temp = (int *)malloc((d-a+1)*sizeof(int));
	while(i<=b&&j<=d)
	{
		if(arr[i]>arr[j]) temp[k++]=arr[j++];
		else temp[k++]=arr[i++];
	}
	while(i<=b) temp[k++]=arr[i++];
	while(j<=d) temp[k++]=arr[j++];
	for(i=0;i<k;i++) arr[a+i]=temp[i];
	free(temp);
}

int main()
{
	int arr[]={3,2,4,5,1,2};
	divide(arr,0,5);
	for (int i = 0; i < 6; ++i)
	{
		cout<<arr[i]<<" ";
	}
}