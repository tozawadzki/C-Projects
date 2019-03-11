#include "pch.h"
#include "Quick.h"
#include <iostream>
#include <cstdlib>

void Quick::randomFill(int * tab, int size)
{
	for (int i = 0; i < size; i++)
		tab[i] = rand() % size + 1;
}

void Quick::reverseFill(int * tab, int size)
{
	for (int i = 0; i < size; i++)
		tab[i] = size - i;
}


void Quick::Display(int * tab, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << tab[i] << std::endl;
}

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
