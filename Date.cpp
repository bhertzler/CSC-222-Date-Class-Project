// Date.cpp, the implementation file for the class Date

// Benjamin Hertzler
// CSC 222
// Date Class Project


#include "Date.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
using namespace std;

// Global Constants
static const string MONTH_NAMES[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
static const int MONTH_LENGTHS[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Public Member Functions

void Date::setDate(int mm, int dd, int yyyy)
{
	try
	{
		if (yyyy > 0 && yyyy < 10000)
			year = yyyy;
		else
		{
			throw range_error("Year Value Out of Range");
		}

		setMonths();

		if (mm > 0 && mm < 13)
			month = mm;
		else
		{
			throw range_error("Month Value Out of Range");
		}

		if (dd > 0 && dd <= monthLength(month))
			day = dd;
		else
		{
			throw range_error("Day Value Out of Range");
		}
	}
	catch (exception err)
	{
		cerr << "ERROR: " << err.what() << ", resetting to default value." << endl;
		year = 1930;
		month = 1;
		day = 1;
	}
}

void Date::getDate(int& m, int& d, int& y) const
{
	m = month;
	d = day;
	y = year;
}

bool Date::isLeapYear(int y) const
{
	return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

int Date::monthLength(int m) const
{
	return months[m - 1].length;
}

string Date::monthName(int m) const
{
	return months[m - 1].name;
}

void Date::print(int format)
{
	switch (format)
	{
	case 1:
		cout << setprecision(2) << month << '/' << day << '/' << setprecision(4) << year << endl;
		break;
	case 2:
		cout << monthName(month) << ' ' << setprecision(2) << day << ", " << setprecision(4) << year << endl;
		break;
	case 3:
		cout << setprecision(2) << day << ' ' << monthName(month) << ' ' << setprecision(4) << year << endl;
		break;
	default:
		cerr << "INVALID OUTPUT FORMAT" << endl;
		break;
	}
}

// Private Member Functions

void Date::setMonths()
{
	for (int i = 0; i < 12; i++)
	{
		months[i].name = MONTH_NAMES[i];
		months[i].length = MONTH_LENGTHS[i];
	}

	if (isLeapYear(year))
		months[1].length = 29;
}

int Date::julian() const
{
	int temp = (month - 14) / 12;
	int jdn = (1461 * (year + 4800 + temp)) / 4;
	jdn += (367 * (month - 2 - 12 * temp)) / 12;
	jdn -= (3 * ((year + 4900 + temp) / 100)) / 4;
	jdn += day;
	jdn -= 32075;
	return jdn;
}

// Operator Overloads

Date Date::operator++()
{
	if (day == monthLength(month))
	{
		day = 1;
		if (month == 12)
		{
			month = 1;
			year++;
			setMonths();
		}
		else
			month++;
	}
	else
		day++;

	return *this;
}

Date Date::operator++(int)
{
	Date temp(month, day, year);

	if (day == monthLength(month))
	{
		day = 1;
		if (month == 12)
		{
			month = 1;
			year++;
			setMonths();
		}
		else
			month++;
	}
	else
		day++;

	return temp;
}

Date Date::operator--()
{
	if (day == 1)
	{
		if (month == 1)
		{
			month = 12;
			year--;
			setMonths();
		}
		else
			month--;
		day = monthLength(month);
	}
	else
		day--;

	return *this;
}

Date Date::operator--(int)
{
	Date temp(month, day, year);

	if (day == 1)
	{
		if (month == 1)
		{
			month = 12;
			year--;
			setMonths();
		}
		else
			month--;
		day = monthLength(month);
	}
	else
		day--;

	return temp;
}

int Date::operator-(const Date& opr) const
{

	Date temp(month, day, year);
	return temp.julian() - opr.julian();

}

ostream& operator<<(ostream& strm, Date& dt)
{
	strm << dt.monthName(dt.month) << ' ' << setprecision(2) << dt.day << ", " << setprecision(4) << dt.year << " ";
	return strm;
}

istream& operator>>(istream& strm, Date& dt)
{
	int temp_m, temp_d, temp_y;
	strm >> temp_m >> temp_d >> temp_y;
	dt.setDate(temp_m, temp_d, temp_y);
	return strm;
}
