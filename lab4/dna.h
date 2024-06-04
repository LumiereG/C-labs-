#pragma once
#include "ndna.h"

class DNA //podw�jna ni� DNA
{
	nicDNA ndna1;
	nicDNA ndna2;

public:
	DNA(); 
	DNA(nicDNA ndna); 

	char operator()(int i, int j) const; 

	DNA klon(DNA& zywnosc); 

	friend ostream& operator<<(ostream& out, const DNA& dna);
};