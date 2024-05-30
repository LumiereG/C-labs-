#include <iostream>
#include "samolot.h"
using namespace std;
int Samolot::starty;
int Samolot::liczba_samolotow_w_powietrzu;
int Samolot::max_id;

Samolot::Samolot() : id{ ++(this->max_id) }
{
	//max_id++;
	liczba_pasazerow = 0;
	liczba_startow = 0;
	status = status_samolotu::PO_NAPRAWIE;

	port_docelowy = nullptr;

}

void Samolot::przygotuj_do_startu(int wysiada, int wsiada, const char* port)
{
	if (static_cast<int>(status) == 2 || static_cast<int>(status) == 3)
	{
		if (wysiada > liczba_pasazerow) liczba_pasazerow = 0;
		else liczba_pasazerow -= wysiada;
		if (wsiada > MAX_LICZBA_PASAZEROW) liczba_pasazerow = MAX_LICZBA_PASAZEROW;
		else liczba_pasazerow += wsiada;
		this->port_docelowy = port;
		status = status_samolotu::GOTOWY;
	}
}

int Samolot::start()
{
	if (static_cast<int>(status) == 0)
	{
		status = status_samolotu::ODLECIAL;
		liczba_startow++;
		liczba_samolotow_w_powietrzu++;
		starty++;
	}
	return starty;
}
void Samolot::laduj()
{
	if (static_cast<int>(status) == 1)
	{
		status = status_samolotu::WYLADOWAL;
		liczba_samolotow_w_powietrzu--;
	}
}

std::ostream& operator<<(std::ostream& out, Samolot& a)
{
	out << "Samolot nr " << a.id << " do ";
	if (a.port_docelowy == nullptr)
	{
		out << "BRAK portu docelowego";
	}
	else {
		out << a.port_docelowy;
	}
	out << " z " << a.liczba_pasazerow << " pasazerami na pokladzie ";
	switch (static_cast<int>(a.status))
	{
	case 0:
		out << "GOTOWY" << endl;
		break;
	case 1:
		out << "ODLECIAL" << endl;
		break;
	case 2:
		out << "WYLADOWAL" << endl;
        break;
	case 3:
		out << "PO_NAPRAWIE" << endl;
        break;
	}
	return out;
}
int Samolot::pobierz_starty() const
{
	return liczba_startow;
}

int Samolot::pobierz_liczba_w_powietrzu()
{
	return liczba_samolotow_w_powietrzu;
}
















