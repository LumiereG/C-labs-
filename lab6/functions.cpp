#include <iostream>
using namespace std;
#include "credit.h"

bool cmp_value(const credit& k1, const credit& k2)
{
	return k1.value > k2.value;
}

bool cmp_value_info(const credit& k1, const credit& k2)
{
	if (k1.value == k2.value) return k1.info > k2.info;
	return k1.value > k2.value;
}

//-----------------------------------------------------------------
void write(credit** cr, int n, const char* description)	//GOTOWA
{
	cout << endl << description;
	for (int i = 0; i < n; i++) cout << *cr[i];
	cout << endl;
}

void sort(credit** cr, int n, bool (*cmp) (const credit& k1, const credit& k2))
{
	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < n-1-i; j++)
		{
			if(cmp(*cr[j],*cr[j+1])) 
			{
				credit* tmp;
				tmp = cr[j];
				cr[j] = cr[j+1];
				cr[j+1] = tmp;
			}
		}

}