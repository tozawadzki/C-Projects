#ifndef MERGE_H_HAS_BEEN_INCLUDED
#define MERGE_H_HAS_BEEN_INCLUDED
#include <iostream>
using namespace std;
class Merge
{
public:
	void MergeSort(int tablica[], int start, int koniec);
	void MergeIt(int tablica[], int start, int srodek, int koniec);
	Merge() {}
};

#endif 