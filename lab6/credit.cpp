#include <iostream>
using namespace std;
#include <iomanip>
#include "credit.h"
#include <math.h>


credit::credit( double value, double percent, int years, int payments_in_year , const char* info ) 
{ 
	this->value = value;
	this->percent = percent;
	this->years = years;
	this->payments_in_year = payments_in_year;
	this->info = info;

}



double credit::payment() const	//rata kredytu
{ 
    double p = percent * 0.01 / payments_in_year;
    double q = 1 + p;
	double n = payments_in_year*years;
	return value*pow(q,n)*(q-1)/(pow(q,n)-1);
}


void credit::write(ostream& out) const
{
	out << endl;
	out << fixed << setprecision(2);

	out << " " <<  setw(10) << left << info;
	out << " credit: " << setw(10) << right << value;
	out << " ( " << setw(3) << right << percent << "%) ";
	out << " years: " << setw(3) << left << years;

	out << " r/r: " << setw(3) << left << payments_in_year;
	out << " payment: "<< setw(10) << payment();
	
}

ostream& operator<<(ostream& out, const credit& os)
{
	os.write(out);
	return out;
}
credit::~credit() {
}

credit* credit::clone()
{
	return new credit(*this);
}


