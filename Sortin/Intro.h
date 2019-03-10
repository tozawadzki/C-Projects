#ifndef INTRO_H_HAS_BEEN_INCLUDED
#define INTRO_H_HAS_BEEN_INCLUDED
#include<iostream>
#include<math.h>

class Intro
{
public:
	 int Partition(int* data, int left, int right);
	 void QuickSortRecursive(int* data, int left, int right);
	 void MaxHeapify(int* data, int heapSize, int index);
	 void HeapSort(int* data, int count);
	 void InsertionSort(int* data, int count);
	 void IntroSort(int* data, int count);
	/*
		int pivot;
	int save;

	void Introsort_true(int tab[], int first, int last, int depth);
	void Introsort(int tab[], int size);
	int Partition(int tab[], int first, int last);
	void Insertion(int tab[], int size);
	void Swap(int *a, int *b);
	void Heap(int tab[], int start, int end);
	void HeapSort(int tab[], int start, int end);
	bool IsSorted(int tab[], int size);
	Intro() {}
	*/
};
#endif
