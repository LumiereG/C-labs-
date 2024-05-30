#pragma once


class Date
{
private:
	int day;
	int month;
	int year;
	
	bool format;

private:
	bool ifLeapYear() const;

public:
	Date(int d = 1, int m = 3, int r = 2024, bool format=false);
	Date(const char* text, bool format=false);
	void setFormat(bool format);
	//friend std::istream& operator>>(std::istream& in, Date& a);
	friend std::ostream& operator<<(std::ostream& out, Date& a);
	Date& operator++();
	Date& operator--();
	Date& operator+=(int a);
	friend bool operator==(const Date&, const Date&);
	friend bool operator<(const Date&, const Date&);
	friend int numberOfDays(const Date&, const Date&);
	friend int numberofYear(const Date& d1);

};

