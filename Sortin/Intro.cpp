#include "pch.h"
#include "Intro.h"
void Intro::randomFill(int * tab, int size)
{
	for (int i = 0; i < size; i++)
		tab[i] = rand() % size + 1;
}
void Intro::reverseFill(int * tab, int size)
{
	for (int i = 0; i < size; i++)
		tab[i] = size - i;
}
void Intro::Display(int * tab, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << tab[i] << std::endl;
}
int Intro::Partition(int* data, int left, int right) {
	int pivot = data[right];
	int temp;
	int i = left;

	for (int j = left; j < right; ++j)
	{
		if (data[j] <= pivot)
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
			i++;
		}
	}

	data[right] = data[i];
	data[i] = pivot;

	return i;
}

 void Intro::QuickSortRecursive(int* data, int left, int right) {
	if (left < right)
	{
		int q = Partition(data, left, right);
		QuickSortRecursive(data, left, q - 1);
		QuickSortRecursive(data, q + 1, right);
	}
}

 void Intro::MaxHeapify(int* data, int heapSize, int index) {
	int left = (index + 1) * 2 - 1;
	int right = (index + 1) * 2;
	int largest = 0;

	if (left < heapSize && data[left] > data[index])
		largest = left;
	else
		largest = index;

	if (right < heapSize && data[right] > data[largest])
		largest = right;

	if (largest != index)
	{
		int temp = data[index];
		data[index] = data[largest];
		data[largest] = temp;

		MaxHeapify(data, heapSize, largest);
	}
}

 void Intro::HeapSort(int* data, int count) {
	int heapSize = count;

	for (int p = (heapSize - 1) / 2; p >= 0; --p)
		MaxHeapify(data, heapSize, p);

	for (int i = count - 1; i > 0; --i)
	{
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;

		--heapSize;
		MaxHeapify(data, heapSize, 0);
	}
}

 void Intro::InsertionSort(int* data, int count) {
	for (int i = 1; i < count; ++i)
	{
		int j = i;

		while ((j > 0))
		{
			if (data[j - 1] > data[j])
			{
				data[j - 1] ^= data[j];
				data[j] ^= data[j - 1];
				data[j - 1] ^= data[j];

				--j;
			}
			else
			{
				break;
			}
		}
	}
}

 void Intro::IntroSort(int* data, int count) {
	int partitionSize = Partition(data, 0, count - 1);

	if (partitionSize < 16)
	{
		InsertionSort(data, count);
	}
	else if (partitionSize > (2 * log(count)))
	{
		HeapSort(data, count);
	}
	else
	{
		QuickSortRecursive(data, 0, count - 1);
	}
}
/*
void Intro::Introsort_true(int tab[], int first, int last, int depth)
{
	while (last - first > 0) {
		if (depth = 0)
			HeapSort(&tab[first], first, last - first + 1);
		else {
			int pivot;
			if (IsSorted(tab, last))
				break;
			pivot = Partition(tab, first, last);
			Introsort_true(tab, pivot + 1, last, depth - 1);
			last = pivot - 1;
		}
	}
}


void Intro::Introsort(int tab[], int size)
{
	Introsort_true(tab, 0, size - 1, (int(2 * log(double(size)))));
	Insertion(tab, size);
}

int Intro::Partition(int tab[], int first, int last)
{
	int pivot, mid = (first+last)/2;
 
	pivot = tab[first] > tab[mid]  ? first : mid;
 
	if( tab[pivot] > tab[last])
		pivot = last;
 
	Swap( &tab[pivot], &tab[first] );
	pivot = first;
 
	while ( first < last ){
		if ( tab[first] <= tab[last] )
			Swap( &tab[pivot++], &tab[first] );
		++first;
	}
 
	Swap (&tab[pivot], &tab[last]);
	return pivot;
}

void Intro::Insertion(int tab[], int size)
{
	int i;
	for (i = 1; i < size; i++) {
		int j, save = tab[i];
		for (j = i; j >= 1 && tab[j - 1] > save; j--)
			tab[j] = tab[j - 1];
		tab[j] = save;
	}
}

void Intro::Swap(int * a, int * b)
{
	int save = *a;
	*a = *b;
	*b = save;
}

void Intro::Heap(int tab[], int start, int end)
{
	int save = tab[start];
	while (start <= end / 2) {
		int k = 2 * start;
		while (k < end && tab[k] < tab[k + 1])
			++k;
		if (save >= tab[k])
			break;
		tab[start] = tab[k];
		start = k;
	}
	tab[start] = save;

}

void Intro::HeapSort(int tab[], int start, int end)
{
	int i;
	for (int i = (end - 1) / 2; i >= start; i--) {
		Heap(tab, i, end - 1);
	}
	for (i = end - 1; i > start; i--) {
		Swap(&tab[i], &tab[start]);
		Heap(tab, start, i - 1);
	}
}

bool Intro::IsSorted(int tab[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (tab[i] > tab[i + 1])
			return false;
		else 
			return true;	
	}
	return false;
}*/


