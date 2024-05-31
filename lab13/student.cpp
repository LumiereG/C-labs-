
#include <iostream>
#include <iomanip>
using namespace std;
#include "student.h"
#include "my_algorithm.h"
   

//-------------------------------------------------------------------
student::student(const std::string &n, const std::string &s, const std::list<int> &p) : name{n}, surname{s}, points{p}
{
}
//-------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out, const student& st)
{
	//uzupe�nij
	//wypisz surname, name, mark
	//do wypisania punkt�w zastosuj my_for_each oraz lambda

	std::cout << st.surname << " " << st.name << " " << "ocena: " <<st.mark << ": ";
	auto wypisz_oceny = [] (int k) {cout << k << " ";};
	my_for_each(st.points.begin(), st.points.end(), wypisz_oceny);
	cout << endl;

	return out;
}
//--------------------------------------------------------------------
int student::sum_of_points() const
{
	if(points.empty()) return 0; //je�li lista punkt�w pusta
	auto plus = [](int sum, int k) {
		return sum += k;
	};
	int sum = 0;
	return my_accumulate(points.begin(), points.end(), sum, plus);
}

//------------------------------------------------------------------
void student::histogram(std::map<int, int>& m) const
{
	auto lam = [&m](int k) {
		m[k]++;
	};
	my_for_each(points.begin(), points.end(), lam);
}

//------------------------------------------------------------------

