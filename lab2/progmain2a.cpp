#include <iostream>
using namespace std;
#include "date.h"


int main()
{
	cout << "----------   ETAP 1    -------------------------" << endl << endl;

	Date d1;		// domy�lnie: 1 3 2024
	Date d2(7);		// 7 i domy�lnie: 3 2024, czyli 7 3 2024
	Date d3(2, 8);	// 2 8 i domy�lne: 2024
	Date d4("24.02.2024");	// zakladamy poprawny format daty (tylko napisy w takim formacie)

	cout << "d1=" << d1 << endl;
	cout << "d2=" << d2 << endl;

	d3.setFormat(true);	//miesiac wypisywany jest s�ownie
	cout << "d3=" << d3 << endl;

	d4.setFormat(true);	//miesi�c wypisywany jest s�ownie
	cout << "d4=" << d4 << endl;


	cout << "----------   ETAP 2    -------------------------" << endl << endl;
	d1 = Date(27, 02, 2024);

	d4 = d1;
	for (int i = 0; i < 6; i++)
		cout << "d4=" << ++d4 << endl;

	cout << "----------   ETAP 3    -------------------------" << endl << endl;
	for (int i = 0; i < 6; i++)
		cout << "d4=" << --d4 << endl;

	cout << "----------   ETAP 4    -------------------------" << endl << endl;
	Date d5 = d4, d6;
	d5 += 7;
	cout << "za tydzien bedzie d5=" << d5 << endl;

	d5 += 14;
	cout << "i jeszcze za 2 tygodnie bedzie d5=" << d5 << endl;

	d6 = d5;
	d5 += -21;
	cout << "a 3 tygodnie temu bylo d5=" << d5 << endl;


	cout << "----------   ETAP 5    -------------------------" << endl << endl;
	if (d5==d6)
		cout << "Daty: " << d5 << " oraz " << d6 << " takie same " << endl;
	else
		cout << "Daty: " << d5 << " oraz " << d6 << " inne " << endl;

	if (d5<d6)
		cout << "Data: " << d5 << " jest wczesniej niz " << d6 << endl;

	cout << "----------   ETAP 6    -------------------------" << endl << endl;

	d5.setFormat(true);
	d6.setFormat(true);
	cout << "Liczba dni od: " << d5<< " do "<< d6<< " wynosi: "<< numberOfDays(d5, d6) << endl;

	d5.setFormat(false);
	d6.setFormat(false);
	cout << "Liczba dni od: " << d6 << " do " << d5 << " wynosi: " << numberOfDays(d6, d5) << endl;
	cout << "Liczba dni od: " << d5 << " do " << d5 << " wynosi: " << numberOfDays(d5, d5) << endl;

	cout << "----------   ETAP 7 (w laboratorium)  -------------------------" << endl << endl;
	d5 = Date(16, 3, 2024);
	cout << d5 << " kolejny dzien: " << ++d5 << endl;
	cout << "numer dnia w roku: " << numberofYear(d5) << endl;

}