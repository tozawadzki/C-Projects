#ifndef QUICK_H_HAS_BEEN_INCLUDED
#define QUICK_H_HAS_BEEN_INCLUDED

class Quick
{
public:
	int pivot, q;
	int Partition(int tab[], int p, int r);
	void QuickSort(int tab[], int p, int r);
	Quick() {}
};

#endif 
