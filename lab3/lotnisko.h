#pragma once
#include "samolot.h"


class Lotnisko
{
private:
	const int id_lotniska;
	static int max_id_lotniska;

	int liczba_samolotow;

	static const int MAX_LICZBA_SAMOLOTOW = 5;
	Samolot* samoloty[MAX_LICZBA_SAMOLOTOW]{ nullptr };

public:
	Lotnisko();

	bool operator+=(Samolot& s);
	void przekieruj(Samolot& s, const char* port) const;
	bool zezwol_na_start(Samolot& s);
	void naprawa(Samolot& s) const;
	friend std::ostream& operator<< (std::ostream& out, Lotnisko& a);
	Samolot* operator[](int i);
	int pobierz_liczba_samolotow();
	friend class Samolot;
};