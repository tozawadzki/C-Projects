#include "pch.h"
#include "Quick.h"
#include <iostream>
#include <cstdlib>

int Quick::Partition(int tab[], int p, int r)
{
	pivot = tab[p];
	int i = p, j = r, w;
	while (true)
	{
		while (tab[j] > pivot)
			j--;
		while (tab[i] < pivot)
			i++;
		if (i < j)
		{
			w = tab[i];
			tab[i] = tab[j];
			tab[j] = w;
			i++;
			j--;
		}
		else
			return j;
	}
}


void Quick::QuickSort(int tab[], int p, int r)
{
	if (p < r)
	{
		q = Partition(tab, p, r);
		QuickSort(tab, p, q);
		QuickSort(tab, q + 1, r);
	}
}
