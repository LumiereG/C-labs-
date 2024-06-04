#pragma once
#include <iostream>
using std::ostream;
class DNA;

enum class nukleozyd { A /*Adenina*/, G /*Guanina*/, C /*Cytozyna*/, T /*Tymina*/ };

class nicDNA //pojedyncza ni� DNA
{
	nukleozyd* nDNA;
	int ilosc_nukleozydow;

public:
	
	nicDNA(int ilosc = 0, const char* nukleozydy = nullptr); 
	nicDNA(int ilosc, nukleozyd nuk); 
	~nicDNA(); 

	char operator()(int i) const; 

	friend ostream& operator<<(ostream& out, const nicDNA& ndna); 

	/* Etap 2 */
	nicDNA(const nicDNA& ndna); 

	nukleozyd& operator[](int i); 

	void dolacz(nicDNA& ndna); 
	int dlugosc() const { return ilosc_nukleozydow; }

	friend nicDNA operator+(const nicDNA& d1, const nicDNA& d2); 
	friend ostream& operator<<(ostream& out, const DNA& dna);
	friend class DNA;
};