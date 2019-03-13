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
	// Zmienne pomocnicze do zliczania czasu
	Timer timeMerge, timeIntro, timeQuick;
	// Tablice przechowuj¹ce czas posortowania
	double introTimeTable[100], quickTimeTable[100], mergeTimeTable[100];
	// Zmienne plikowe
	fstream fileIntro, fileQuick, fileMerge;
	Quick Q;
	Merge M;
	Intro I;
	int size;
	// Wyczyszczenie plików
	fileIntro.open("IntroData.txt", ofstream::out | ofstream::trunc);
	fileIntro.close();
	fileQuick.open("QuickData.txt", ofstream::out | ofstream::trunc);
	fileQuick.close();
	fileMerge.open("MergeData.txt", ofstream::out | ofstream::trunc);
	fileMerge.close();
	
	// Podanie rozmiaru
	cout << "Podaj ilosc liczb do posortowania: ";
	cin >> size;
	int *tab = new int[size];
	
	for (int i = 0; i < 100; i++)
	{
		M.randomFill(tab, size);
		//Struktury dynamiczne
		// Przygotowaæ wczesniej dame
		// Puscic z pliku
		
		//M.MergeSort(tab, 0, 0.25*size);
		//M.MergeSort(tab, 0, 0.5*size);
		//M.MergeSort(tab, 0, 0.75*size);
		//M.MergeSort(tab, 0, 0.95*size);
		//M.MergeSort(tab, 0, 0.99*size);
		//M.MergeSort(tab, 0, 0.997*size);
		//M.reverseFill(tab, 0, size);
		timeMerge.start();
		M.MergeSort(tab, 0, size - 1);
		timeMerge.stop();
		mergeTimeTable[i] = timeMerge.getElapsedTime();
	}
	cout << "Merge gotowy" << endl;
	
	/*
	for (int i = 0; i < 100; i++)
	{
		Q.randomFill(tab, size);
		//Q.QuickSort(tab, 0.25*size);
		//Q.QuickSort(tab, 0.5*size);
		//Q.QuickSort(tab, 0.75*size);
		//Q.QuickSort(tab, 0.95*size);
		//Q.QuickSort(tab, 0.99*size);
		//Q.QuickSort(tab, 0.997*size);
		//Q.reverseFill(tab, size);
		timeQuick.start();
		Q.QuickSort(tab, 0, size - 1);
		timeQuick.stop();
		quickTimeTable[i] = timeQuick.getElapsedTime();
	}
	cout << "Quick gotowy" << endl;
	
	for (int i = 0; i < 100; i++)
	{
		I.randomFill(tab, size);
		timeIntro.start();
		//I.IntroSort(tab, 0.25*size - 1);
		//I.IntroSort(tab, 0.5*size - 1);
		//I.IntroSort(tab, 0.75*size - 1);
		//I.IntroSort(tab, 0.95*size - 1);
		//I.IntroSort(tab, 0.99*size - 1);
		//I.IntroSort(tab, 0.997*size - 1);
		//I.reverseFill(tab, size);
		I.IntroSort(tab, size - 1);
		timeIntro.stop();
		introTimeTable[i] = timeIntro.getElapsedTime();
	}
	cout << "Intro gotowy" << endl;
	*/
	
	fileMerge.open("MergeData.txt", ios::out);
	for (int i = 0; i < 100; i++)
		fileMerge << mergeTimeTable[i] << endl;
	fileMerge << "Koniec" << endl;
	fileMerge.close();
	
	/*
	fileQuick.open("QuickData.txt");
	for (int i = 0; i < 100; i++)
		fileQuick << quickTimeTable[i] << endl;
	fileQuick.close();
	

	fileIntro.open("IntroData.txt");
	for (int i = 0; i < 100; i++)
		fileIntro << introTimeTable[i] << endl;
	fileIntro.close();
	*/
	
	delete[] tab;
	
	return 0;
}

