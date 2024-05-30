#pragma once
class Ulamek
{
public:
	~Ulamek();
	Ulamek();
	Ulamek(const Ulamek& a);
	void Wczytaj();
	void Wypisz() const;
	friend Ulamek operator+(Ulamek a, Ulamek b);
	friend std::istream& operator>>(std::istream& in, Ulamek& a);
	friend std::ostream& operator<<(std::ostream& out, Ulamek& a);
private:
	int licznik;
	int mianownik;
	void Skracaj();
};
int NWD(int a, int b);