#include "dna.h"
#include <iostream>
using namespace std;


DNA::DNA() : ndna1(), ndna2()
{

}
DNA::DNA(nicDNA ndna) : ndna1(), ndna2()
{
	this->ndna1 = ndna;
	ndna2 = nicDNA(ndna1.ilosc_nukleozydow);
	for (int i = 0; i < ndna.ilosc_nukleozydow; i++)
	{
		switch (ndna1.nDNA[i])
		{
		case nukleozyd::A:
			this->ndna2.nDNA[i] = nukleozyd::T;
			break;
		case nukleozyd::T:
			this->ndna2.nDNA[i] = nukleozyd::A;
			break;
		case nukleozyd::G:
			this->ndna2.nDNA[i] = nukleozyd::C;
			break;
		case nukleozyd::C:
			this->ndna2.nDNA[i] = nukleozyd::G;
			break;
		}
	}
}

char DNA::operator()(int i, int j) const
{
	if (i == 1)
	{
		return this->ndna1(j);
	}
	else return this->ndna2(j);
}

DNA DNA::klon(DNA& zywnosc)
{
	if (this->ndna1.dlugosc() > zywnosc.ndna1.dlugosc()) return DNA();
int a = 0, c = 0, t = 0, g = 0;
for (int i = 0; i < this->ndna1.dlugosc(); i++)
{
if (this->ndna1[i] == nukleozyd::A) a++;
else if (this->ndna1[i] == nukleozyd::C) c++;
else if (this->ndna1[i] == nukleozyd::T) t++;
else g++;
}
for (int i = 0; i < zywnosc.ndna1.dlugosc(); i++)
{
if (zywnosc.ndna1[i] == nukleozyd::A) a--;
else if (zywnosc.ndna1[i] == nukleozyd::C) c--;
else if (zywnosc.ndna1[i] == nukleozyd::T) t--;
else g--;
}
/*std::cout << zywnosc;
std::cout << this;
std::cout << a << c << t << g;*/
if (a <= 0 && t <= 0 && c <= 0 && g <= 0) return *this;
return DNA();
}


ostream& operator<<(ostream& out, const DNA& dna)
{
	cout << "-------" << endl;
	for (int i = 0; i < dna.ndna1.ilosc_nukleozydow; i++)
	{
		cout << " |";
		switch (dna.ndna1.nDNA[i])
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
		cout << '-';
		switch (dna.ndna2.nDNA[i])
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
		cout << "|" << endl;
	}
	cout << "-------" << endl;
	return out;
}
