#include <iostream>
#include "lotnisko.h"
#include "samolot.h"
using namespace std;

int Lotnisko::max_id_lotniska;

Lotnisko::Lotnisko() : id_lotniska{ ++(max_id_lotniska) }
{
	liczba_samolotow = 0;
	for (int i = 0; i < MAX_LICZBA_SAMOLOTOW; i++)
	{
		samoloty[i] = nullptr;
	}
}

bool Lotnisko::operator+=(Samolot& s)
{
	if (s.status == Samolot::status_samolotu::ODLECIAL || s.status == Samolot::status_samolotu::PO_NAPRAWIE)
	{
		if (liczba_samolotow < MAX_LICZBA_SAMOLOTOW)
		{
			liczba_samolotow++;
			samoloty[liczba_samolotow - 1] = &s;
			if (s.status == Samolot::status_samolotu::ODLECIAL) s.laduj();
			return true;
		}
		return false;
	}
    return true;
}

bool Lotnisko::zezwol_na_start(Samolot & s)
{
	for (int i = 0; i < liczba_samolotow; i++)
	{
		if (samoloty[i] == &s)
		{
			s.start();
			if (s.status == Samolot::status_samolotu::ODLECIAL)
			{
				for (int j = i; j < liczba_samolotow - 1; j++)
				{
						samoloty[j] = samoloty[j + 1];
				}
			}
			liczba_samolotow--;
			return true;
		}
    }
    return false;
}

void Lotnisko::przekieruj(Samolot& s, const char* port) const
{
	if (s.status == Samolot::status_samolotu::ODLECIAL)
	{
		s.port_docelowy = port;
	}
}

std::ostream& operator<<(std::ostream& out, Lotnisko& a)
{
	out << "Lotnisko nr " << a.id_lotniska << endl;
	for (int i = 0; i < a.liczba_samolotow; i++)
	{
		out << i+1 << ". ";
		cout << *(a.samoloty[i]);
	}
	return out;
	
}

Samolot* Lotnisko::operator[](int i)
{
	return this->samoloty[i];
}

int Lotnisko::pobierz_liczba_samolotow()
{
	return this->liczba_samolotow;
}

void Lotnisko::naprawa(Samolot& s) const
{
	if (s.status == Samolot::status_samolotu::WYLADOWAL)
	{
		s.liczba_pasazerow = 0;
		s.liczba_startow = 0;
		s.status = Samolot::status_samolotu::PO_NAPRAWIE;

		s.port_docelowy = nullptr;

	}
}