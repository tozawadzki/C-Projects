#include "pch.h"
#include <iostream>
#include <fstream>
#include "Quick.h"
#include "Merge.h"
#include "Intro.h"
#include "Timer.h"
#include <algorithm>
#include <functional>

#define ROZMIAR1 10000
#define ROZMIAR2 50000
#define ROZMIAR3 100000
#define ROZMIAR4 500000
#define ROZMIAR5 1000000

using namespace std;

int main()
{
	Timer timeMerge, timeIntro, timeQuick, timeBasic;
	fstream fileIntro, fileQuick, fileMerge;
	Quick Q;
	Merge M;
	Intro I;
	int size;
	cout << "Podaj ilosc liczb do posortowania: ";
	cin >> size;
	int *tab = new int[size];

	for (int i = 0; i < size; i++)
	{
		tab[i] = rand() % size + 1;
	}
	
	timeMerge.start();
	M.MergeSort(tab, 0, size-1);
	timeMerge.stop();
	cout << "Sortowanko Mergesort:" <<  timeMerge.getElapsedTime();
	
	for (int i = 0; i < size; i++)
	{
		tab[i] = rand() % size + 1;
	}

	timeQuick.start();
	Q.QuickSort(tab, 0, size - 1);
	timeQuick.stop();
	cout << "\nSortowanko Quick:" << timeQuick.getElapsedTime();
	

	for (int i = 0; i < size; i++)
	{
		tab[i] = rand() % size + 1;
	}
	
	timeIntro.start();
	I.IntroSort(tab, size - 1);
	timeIntro.stop();
	cout << "\nSortowanko Intro:" << timeIntro.getElapsedTime();

	for (int i = 0; i < size; i++)
	{
		tab[i] = rand() % size + 1;
	}

	timeBasic.start();
	sort(tab, tab+ size);
	timeBasic.stop();
	cout << "\nSortowanko zwykle:" << timeBasic.getElapsedTime();
/*
	for (int i = 0; i < size; i++)
	{
		cout << tab[i] << endl;
	}
	*/
	/*fileMerge.open("MergeData.txt", ios::out);
		for (int i = 0; i < size; i++)
			fileMerge << tab[i] << endl; 

			fileMerge.close();*/
	delete[] tab;

	return 0;
}

