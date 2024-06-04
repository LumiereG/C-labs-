#include <iostream>
#include "ndna.h"
#include "dna.h"

using namespace std;

int main()
{
	cout << "===================== ETAP 1 =====================" << endl;

	nicDNA ndna1; 
	cout << "ndna1:\n" << ndna1 << endl;
	const nicDNA ndna2 = 3;
	cout << "ndna2:\n" << ndna2(0) << ndna2(1) << ndna2(2) << endl << endl;
	nicDNA ndna3(5, "ACAGT");
	cout << "ndna3:\n" << ndna3(0) << ndna3(1) << ndna3(2) << ndna3(3) << ndna3(4) << endl;
	cout << ndna3 << endl;
	nicDNA ndna4(7, nukleozyd::T);
	cout << "ndna4:\n" << ndna4 << endl;

	cout << endl;
	cout << "===================== ETAP 2 =====================" << endl;

	ndna4[1] = nukleozyd::C;
	cout << "ndna4:\n" << ndna4 << endl;
	nicDNA ndna5 = ndna2 + ndna3;
	cout << "ndna5:\n" << ndna5 << endl;
	nicDNA ndna6(3, "ACT");
	nicDNA ndna7(ndna6);
	ndna6[0] = nukleozyd::G;
	cout << "ndna6:\n" << ndna6 << endl;
	cout << "ndna7:\n" << ndna7 << endl;
	ndna6.dolacz(ndna7);
	cout << "ndna6:\n" << ndna6 << endl;
	cout << "ndna7:\n" << ndna7 << endl;


	cout << endl;
	cout << "===================== ETAP 3 =====================" << endl;
	DNA dna1;
	cout << "dna1:\n" << dna1 << endl;
	DNA dna2(ndna6);
	cout << "dna2:\n" << dna2 << endl;
	cout << "dna2(1, 3): " << dna2(1, 3) << endl << endl;
	nicDNA ndna8 = nicDNA(10);
	DNA dna3(ndna8);
	DNA dna4 = dna2.klon(dna3);
	cout << "dna4:\n" << dna4 << endl;
	DNA dna5(ndna6 + nicDNA(3));
	DNA dna6 = dna2.klon(dna5);
	cout << "dna6:\n" << dna6 << endl;

	return 0;
}