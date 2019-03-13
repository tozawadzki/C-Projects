#include "pch.h"
#include "Merge.h"

void Merge::randomFill(int * tab, int size)
{
	for (int i = 0; i < size; i++)
		tab[i] = rand() % size + 1;
}

void Merge::reverseFill(int * tab, int size)
{
	for (int i = 0; i < size; i++)
		tab[i] = size - i;
}

void Merge::Display(int * tab, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << tab[i] << std::endl;
}

void Merge::MergeSort(int tablica[], int start, int koniec)
{
	int srodek;

	if (start != koniec)
	{
		srodek = (start + koniec) / 2;
		MergeSort(tablica, start, srodek);
		MergeSort(tablica, srodek + 1, koniec);
		MergeIt(tablica, start, srodek, koniec);
	}
	/*if (start >= end)
	{
		int center = (start + end )/2;
		MergeSort(tab, start, center);
		MergeSort(tab, center+1, end);
		MergeIt(tab, start, center, end);
	}*/
}

void Merge::MergeIt(int tablica[], int start, int srodek, int koniec)
{
	int *tab_pom = new int[koniec - start + 1]; // utworzenie tablicy pomocniczej
	int i = start, j = srodek + 1, k = 0; // zmienne pomocnicze

	while (i <= srodek && j <= koniec)
	{
		if (tablica[j] < tablica[i])
		{
			tab_pom[k] = tablica[j];
			j++;
		}
		else
		{
			tab_pom[k] = tablica[i];
			i++;
		}
		k++;
	}

	if (i <= srodek)
	{
		while (i <= srodek)
		{
			tab_pom[k] = tablica[i];
			i++;
			k++;
		}
	}
	else
	{
		while (j <= koniec)
		{
			tab_pom[k] = tablica[j];
			j++;
			k++;
		}
	}

	for (i = 0; i <= koniec - start; i++)
		tablica[start + i] = tab_pom[i];
	delete[] tab_pom;
}
