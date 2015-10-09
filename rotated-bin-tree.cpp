#include<bits/stdc++.h>
using namespace std;

int main()
{
	std::vector<int> arr = {1,2,3,4};
	int mid,start = 0, end = arr.size()-1;
	while(start<=end)
	{
		mid = (start + end)/2;
		if(mid<end&&arr[mid]>arr[mid+1]) break;
		else if(start<mid&&arr[mid-1]>arr[mid]) { mid=mid-1; break; }
		else if(arr[start]>=arr[mid]) end = mid -1;
		else start = mid + 1;
	}
	if(end<start) cout<<"-1";
	else cout<<mid;
}