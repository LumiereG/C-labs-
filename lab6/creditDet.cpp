#include <iostream>
using namespace std;
#include <iomanip>
#include "creditDet.h"


//-----------------------------------------------------------------
void creditDet::init_projection(int payments, double* projection)
{
	this->projection = nullptr;

	if (payments > 0)
	{
		this->projection = new (nothrow) double[payments];
		if (!this->projection)  return;

		for (int i = 0; i < payments; i++)
			this->projection[i] = projection ? projection[i] : 0;
	}
}
//-------------------------------------------------------------------
creditDet::creditDet(double value, double percent, int years, int payments_in_year, const char* info) : credit(value, percent, years, payments_in_year, info)
{
	init_projection(payments(), projection);
	payoff();
}

//-----------------------------------------------------------
void creditDet::payoff() const	// ile creditu jeszcze do sp�acenia po wplaceniu "i" rat								//wypelnia tablic� projection			
{
	double p = percent * 0.01 / payments_in_year;
	double r = payment();
	for(int i = 0; i < payments(); i++){
		double w = value;
		for(int j = 0; j < i+1; j++)
		{
			double odsetki = w*p;
			w-= r - odsetki;
		} 
		projection[i] = w;
	}
}
//-----------------------------------------------------------
void creditDet::write(ostream& out) const
{
	credit::write(out);
	out << endl << " projection: [ ";
	for(int i = 0; i < payments(); i++) {
		out << projection[i] << " ";
	}
	out << "]";
}
creditDet::creditDet(const creditDet& k) : credit(k)
{
	init_projection(k.payments(), k.projection);
}
creditDet& creditDet::operator=(const creditDet& k)
{
	credit::operator=(k);
	delete[] projection;
	init_projection(k.payments(), k.projection);
	return *this;
}
creditDet::~creditDet()
{
	delete[] projection;
}
credit* creditDet::clone() {
	return new creditDet(*this);
};
//-------------------------------------------------------------
