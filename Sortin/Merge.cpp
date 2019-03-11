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
	int *tab_pom = new int[(koniec - start)]; // utworzenie tablicy pomocniczej
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

	/*int *tab_tmp = new int[(end - start+1)];
	int i = start;
	int j = centre + 1;
	int k = 0;

	while (i <= centre && j <= end)
	{

		if (tab[j] <= tab[i])
		{
			tab_tmp[k] = tab[j];
			j++;
		}
		else
		{
			tab_tmp[k] = tab[i];
			i++;
		}
		k++;
	}

	if (i > centre)
	{
		for (int pom = j; pom <= end; pom++)
		{
			tab_tmp[k] = tab[i];
			k++;
		}
	}
	else
	{
		for (int pom = i; pom <= centre; pom++)
		{
			tab_tmp[k] = tab[pom];
			k++;
		}
	}

	for (int pom = 0; pom <= (end - start); pom++)
	{
		tab[pom + start] = tab_tmp[pom];
	}
	delete[] tab_tmp;*/
}

