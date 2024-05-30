#include <iostream>
using namespace std;
#include "ulamek.h"
Ulamek::~Ulamek()
{
	cout << "Koniec" << endl;
}
Ulamek::Ulamek()
{
	cout << "Object created" << endl;
}
Ulamek::Ulamek(const Ulamek& a)
{
	licznik = a.licznik;
	mianownik = a.mianownik;
	cout << "Object copy" << endl;
}
/* void Ulamek::Wczytaj()
{
	cout << "Licznik: " ;
	cin >> this->licznik;
	cout << "Mianownik: ";
	cin >> this->mianownik;
	while (!mianownik)
	{
		cout << "Mianownik musi być różny od 0" << endl;
		cout << "Mianownik: ";
		cin << this->mianownik;
	}
}
*/
/* void Ulamek::Wypisz() const
{
	if (licznik == 0 || mianownik == 1) cout << "Liczba: " << licznik << endl;
	else cout << "Liczba: " << licznik << "/" << mianownik << endl;
}
*/

int NWD(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
void Ulamek::Skracaj()
{
	int liczba = NWD(this->licznik, this->mianownik);
	this->licznik /= liczba;
	this->mianownik /= liczba;
	if (licznik < 0 && mianownik < 0 || licznik > 0 && mianownik < 0)
	{
		licznik = -licznik;
		mianownik = -mianownik;
	}
}
Ulamek operator+(Ulamek a, Ulamek b)
{
	Ulamek c;
	int nwd = NWD(a.mianownik, b.mianownik);
	c.licznik = a.licznik * b.mianownik / nwd + b.licznik * a.mianownik / nwd;
	c.mianownik = a.mianownik * b.mianownik / nwd;
	c.Skracaj();
	return c;
}
std::istream& operator>>(std::istream& in, Ulamek& a)
{

	cout << "Licznik: ";
	cin >> a.licznik;
	cout << "Mianownik: ";
	cin >> a.mianownik;
	while (!a.mianownik)
	{
		cout << "Mianownik musi być różny od 0" << endl;
		cout << "Mianownik: ";
		cin >> a.mianownik;
	}
	a.Skracaj();
	return in;
}
std::ostream& operator<<(std::ostream& out, Ulamek& a)
{
	if (a.licznik == 0 || a.mianownik == 1) out << "Liczba: " << a.licznik << endl;
	else out << "Liczba: " << a.licznik << "/" << a.mianownik << endl;
	return out;
}