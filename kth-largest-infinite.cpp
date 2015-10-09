#include<bits/stdc++.h>
using namespace std;

class heap{
private:
	int *array;
	int heap_size;
public:
	heap(int arr[], int size);
	void buildheap();
	int extractmin();
	void heapify(int pos);
	int parent(int i) { return i/2;}

}