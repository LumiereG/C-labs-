#pragma once
   
#include <ostream>
#include <string>
#include <list>
#include <map>

class student
{
	friend class evaluation;

public:
	//ETAP 1
	student() = default;
    student(const std::string &name, const std::string &surname, const std::list<int> &points);
	friend std::ostream& operator<<(std::ostream& out, const student& st);

	//ETAP 2 - sortowanie (wg surname, name)
	

	//ETAP 3
    int sum_of_points() const;
	
	//ETAP 5
    void histogram(std::map<int, int>& m) const;

private:
    std::string name, surname;
    std::list<int> points;			//lista punkt�w studenta (warto�ci ca�kowite)
	int mark=2;						//lufa (dla uproszczenia tylko warto�ci ca�kowite 3, 4, 5)
};



