#ifndef QUICK_H_HAS_BEEN_INCLUDED
#define QUICK_H_HAS_BEEN_INCLUDED

// Sortowanie szybkie
// Z³o¿onoœæ czasowa : O (nlogn)
// Przypadek pesymistyczny: O (n^2)
class Quick
{
public:
	int pivot, q;
	void randomFill(int *tab, int size);
	void reverseFill(int *tab, int size);
	void Display(int *tab, int size);
	int Partition(int tab[], int p, int r);
	void QuickSort(int tab[], int p, int r);
	Quick() {}
};

#endif 
