#include "ndna.h"
#include <iostream>
using namespace std;

nicDNA::nicDNA(int ilosc, const char* nukleozydy)
{
	this->ilosc_nukleozydow = ilosc;
	if (ilosc == 0)
	{
		this->nDNA = nullptr;
		return;
	}
	nDNA = new nukleozyd[ilosc];
	if (nukleozydy == nullptr)
	{
		for (int i = 0; i < ilosc; i++)
		{
			nDNA[i] = nukleozyd::A;
		}
		return;
	}
	for (int i = 0; i < ilosc; i++)
	{
		switch (nukleozydy[i])
		{
		case 'A':
			nDNA[i] = nukleozyd::A;
			break;
		case 'G':
			nDNA[i] = nukleozyd::G;
			break;
		case 'C':
			nDNA[i] = nukleozyd::C;
			break;
		case 'T':
			nDNA[i] = nukleozyd::T;
			break;
		}
	}
}
nicDNA::nicDNA(int ilosc, nukleozyd nuk)
{
	this->ilosc_nukleozydow = ilosc;
	nDNA = new nukleozyd[ilosc];
	for (int i = 0; i < ilosc; i++)
	{
		nDNA[i] = nuk;
	}
}
nicDNA::~nicDNA()
{
	delete[] nDNA;
}

char nicDNA::operator()(int i) const
{
	switch (this->nDNA[i])
	{
	case nukleozyd::A:
		return 'A';
		break;
	case nukleozyd::G:
		return 'G';
		break;
	case nukleozyd::C:
		return 'C';
		break;
	case nukleozyd::T:
		return 'T';
		break;
	default: 
		return ' ';
	}
}

ostream& operator<<(ostream& out, const nicDNA& ndna)
{
	cout << "-----" << endl;
	for (int i = 0; i < ndna.ilosc_nukleozydow; i++)
	{
		cout << " |";
		switch (ndna.nDNA[i])
		{
		case nukleozyd::A:
			cout << 'A';
			break;
		case nukleozyd::G:
			cout << 'G';
			break;
		case nukleozyd::C:
			cout << 'C';
			break;
		case nukleozyd::T:
			cout << 'T';
			break;
		}
		cout << '-' << endl;
	}
	return out;
}
nukleozyd& nicDNA::operator[](int i)
{
	return this->nDNA[i];
}

nicDNA operator+(const nicDNA& d1, const nicDNA& d2)
{
	nicDNA d3(d1.ilosc_nukleozydow + d2.ilosc_nukleozydow);
	for (int i = 0; i < d1.ilosc_nukleozydow; i++)
	{
		d3.nDNA[i] = d1.nDNA[i];
	}
	for (int i = 0; i < d2.ilosc_nukleozydow; i++)
	{
		d3.nDNA[i + d1.ilosc_nukleozydow] = d2.nDNA[i];
	}
	return d3;
}

nicDNA::nicDNA(const nicDNA& ndna)
{
	this->ilosc_nukleozydow = ndna.ilosc_nukleozydow;
	this->nDNA = new nukleozyd[ilosc_nukleozydow];
	for (int i = 0; i < ndna.ilosc_nukleozydow; i++)
	{
		this->nDNA[i] = ndna.nDNA[i];
	}

}
void nicDNA::dolacz(nicDNA& ndna)
{
	nicDNA copy = *this;
	this->nDNA = new nukleozyd[ilosc_nukleozydow + ndna.ilosc_nukleozydow];
	for (int i = 0; i < ilosc_nukleozydow; i++)
	{
		this->nDNA[i] = copy.nDNA[i];
	}
	for (int i = ilosc_nukleozydow; i < ilosc_nukleozydow + ndna.ilosc_nukleozydow; i++)
	{
		this->nDNA[i] = ndna[i - ilosc_nukleozydow];
	}
	this->ilosc_nukleozydow += ndna.ilosc_nukleozydow;
	delete[] ndna.nDNA;
	ndna.ilosc_nukleozydow = 0;
	ndna.nDNA = nullptr;
}