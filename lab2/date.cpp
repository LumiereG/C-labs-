#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include "date.h"

const int M = 12;	//liczba miesi�cy w roku
int dl[M] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
string mn[M] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

Date::Date(int d, int m, int y, bool format) : day{ d }, month{ m }, year{ y }, format{ format } {}
Date::Date(const char* text, bool format)
{
    this->format = format;
    this->day = (static_cast<int>(text[0]) - 48) * 10 + static_cast<int>(text[1]) - 48;
    this->month = (static_cast<int>(text[3]) - 48) * 10 + (static_cast<int>(text[4]) - 48);
    this->year = (static_cast<int>(text[6]) - 48) * 1000 + (static_cast<int>(text[7]) - 48) * 100 + (static_cast<int>(text[8]) - 48) * 10 + static_cast<int>(text[9]) - 48;
}

bool Date::ifLeapYear() const
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

void Date::setFormat(bool format)
{
    this->format = format;
}

std::ostream& operator<<(std::ostream& out, Date& a)
{
    cout << setw(2) << a.day << ".";
    if (!a.format)
    {
        cout << setw(2) << a.month;
    }
    else
    {
        cout << mn[a.month - 1];
    }
    cout << "." << setw(4) << a.year << endl;
    return out;
}

Date& Date::operator++()
{
    if(ifLeapYear()) dl[1] = 29;
    if (this->day == dl[this->month - 1])
    {
        if (this->month == 12)
        {
            this->month = 1;
            this->year++;
        }
        else this->month++;
        this->day = 1;
    }
    else
    {
        this->day++;
    }
    dl[1] = 28;
    return *this;
}

Date& Date::operator--()
{
    if(ifLeapYear()) dl[1] = 29;
    if (this->day == 1)
    {
        if (this->month == 1)
        {
            this->month = 12;
            this->year--;
        }
        else this->month--;
        this->day = dl[this->month - 1];
    }
    else
    {
        this->day--;
    }
    dl[1] = 28;
    return *this;
}

Date& Date::operator+=(int a)
{
    if(ifLeapYear()) dl[1] = 29;
    this->day = this->day + a;
    if (a > 0)
    {
        while (this->day > dl[this->month - 1])
        {
            this->day -= dl[this->month - 1];
            if (this->month == 12)
            {
                this->year++;
                this->month = 1;
            }
            else
            {
                this->month++;
            }
        }
    }
    else
    {
        while (this->day < 1)
        {
            this->day += dl[this->month - 1];
            if (this->month == 1)
            {
                this->year--;
                this->month = 12;
            }
            else
            {
                this->month--;
            }
        }
    }
    dl[1] = 28;
    return *this;
}

bool operator==(const Date& a, const Date& b)
{
    if (a.day == b.day && a.month == b.month && a.year == b.year) return true;
    else return false;
}

bool operator<(const Date& a, const Date& b)
{
    if(a.year < b.year || (a.year == b.year && a.month < b.month) || (a.year == b.year && a.month == b.month && a.day < b.day)) return true;
    else return false;
}

int numberOfDays(const Date& a, const Date& b)
{
    int i = 0;
    Date pier{ a.day, a.month, a.year };
    Date drug{ b.day, b.month, b.year };
    if (pier < drug)
    {
        while (!(pier == drug))
        {
            ++pier;
            i++;
        }
        return i;
    }
    if (drug < pier)
    {
        while (!(pier == drug))
        {
            ++drug;
            i++;
        }
        return i;
    }
    return i;
}

int numberofYear(const Date& d1)
{
    if (d1.ifLeapYear()) dl[1] = 39;
    else dl[1] = 28;
    Date a(1,1,d1.year);
    return numberOfDays(d1, a);
}



    



