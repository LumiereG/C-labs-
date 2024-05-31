
#include <map>
#include <iomanip>
#include "evaluation.h"
#include "my_algorithm.h"
#include <fstream>
using namespace std;

//wystawianie ocen (tylko ca�kowite) na podstawie punkt�w: >=55p ocena 3; >=70p ocena 4; >=85p ocena 5
const map<int, int, greater<int>> evaluation::levels = { { 55, 3}, { 70, 4}, { 85, 5} };

//ETAP 1
evaluation::evaluation(const string& file_name)
{
	std::ifstream wej(file_name);
	student a;
	while(!wej.eof())
	{
		wej >> a.name;
		wej >> a.surname;
		if (!wej) break;
		int k;
		a.points.clear();
		while(wej >> k)
		{
			a.points.push_back(k);
		}
		wej.clear();
		students.push_back(a);
	}
	wej.close();

}

ostream& operator<<(ostream& out, const evaluation& e)
{
	auto wypisz_stud = [&out] (student a) { out << a;};
	my_for_each(e.students.begin(), e.students.end(), wypisz_stud);
	return out;
}
//---------------------------------------------------------------
//ETAP 2
void evaluation::sort()	//sortowanie wg surname, name (studenta)
{
	auto f = [](const student& a, const student& b)
	{
		if (a.surname == b.surname) return a.name < b.name;
		else return a.surname < b.surname;
	};
	students.sort(f);

}
//---------------------------------------------------------------
//ETAP 3

void evaluation::set_marks() 
{
	auto oceny = [](student& a) {
		int sum = a.sum_of_points();
		auto por = [&sum](pair<int, int> b)
		{
			return sum > b.first;
		};
		auto it = my_find_if(levels.begin(), levels.end(), por);
		if (it != levels.end()) a.mark = it->second;
	};
	my_for_each(students.begin(), students.end(), oceny);
}

void evaluation::reset_points(const int& p) 
{
	auto dodawanie = [&p](student& a) {
		auto por = [&p](int point)
		{
			if (point > 0) return point + p;
			return point;
		};
		my_transform(a.points.begin(), a.points.end(),a.points.begin(), por);
	};
	my_for_each(students.begin(), students.end(), dodawanie);


}

//---------------------------------------------------------------
//ETAP 4
void evaluation::clear_not_passing()
{
	auto war = [](const student& a)
	{
		return a.mark == 2;
	};
	students.remove_if(war);

}
//---------------------------------------------------------------------
//ETAP 5
std::map<int,int> evaluation::histogram(ostream& out) const
{
    map<int, int> m;

	my_for_each(students.begin(), students.end(), [&m](const student& a) {
		a.histogram(m);
		});
	//uzupe�nij: wype�nij map� m
	//do listy student�w zastosuj my_for_each oraz lambda
	//dla ka�dego wywo�aj jego metod� histogram

  	

	my_for_each(m.begin(), m.end(), [](pair<int, int> a) {
		cout << "pkt " << a.first << ": ";
		for (int i = 0; i < a.second; i++)
			cout << "*";
		cout << endl;
		});
	//uzupe�nij: wypisz histogram (liczba punkt�w oraz odp. im liczba zada� oznaczona *)
	//do mapy m zastosuj my_for_each oraz lambda

	return m;
}
//----------------------------------------------------------------

