#include<bits/stdc++.h>

using namespace std;

class heap{
public:
	int maxsize;
	int size;
	int *arr;
	void heapify(int i);
	void buildheap(int ar[], int siz);
	void deletemax();
	//void insert(int i);
	int left(int i) {return 2*i;}
	int right(int i) {return 2*i+1;}
	int parent(int i) {return i/2;}
	heap(int i){ arr = (int*)malloc(i*sizeof(int)); maxsize = i;}
};

void heap::heapify(int i)
{
	int largest = i;
	if(left(i)<=size&&arr[left(i)]>arr[largest]) largest = left(i);
	if(right(i)<=size&&arr[right(i)]>arr[largest]) largest = right(i);
	if(largest!=i) { swap(arr[largest],arr[i]); return heapify(largest); }
	else return;
}

void heap::buildheap(int ar[], int siz)
{
	int i;
	size = siz;
	for(i = 1; i <= siz; i++) arr[i]=ar[i];
	i = siz/2;
	for(;i>0;i--) heapify(i);
}

void heap::deletemax()
{
	arr[1]=arr[size];
	size--;
	heapify(1);
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,3,2,4,6};
	heap x(10);
	x.buildheap(arr,5);
	cout<<x.arr[1]<<x.arr[2]<<x.arr[3];
	return 0;
}