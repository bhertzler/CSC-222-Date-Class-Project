// Date.cpp, the implementation file for the class Date

// Benjamin Hertzler
// CSC 222
// Date Class Project


#include "Date.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Global Constants
const string MONTH_NAMES[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const int MONTH_LENGTHS[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void Date::setDate(int mm, int dd, int yyyy)
{
	if (yyyy > 0 && yyyy < 10000)
		year = yyyy;
	else
		year = 1930;

	setMonths;

	if (mm > 0 && mm < 12)
		month = mm;
	else
		month = 1;

	if (dd > 0 && dd <= monthLength(month))
		day = dd;
	else
		day = 1;
}

void Date::getDate(int& m, int& d, int& y)
{
	m = month;
	d = day;
	y = year;
}

bool Date::isLeapYear(int y)
{
	if (y % 4 == 0 && y % 100 == 0)
		return true;
	else
		return false;
}

int Date::monthLength(int m)
{
	return months[m - 1].length;
}

string Date::monthName(int m)
{
	return months[m - 1].name;
}

void Date::printMDY()
{
	cout << setprecision(2) << month << "/" << day << "/" << setprecision(4) << year << endl;
}

void Date::printLongMDY()
{
	cout << monthName(month) << " " << setprecision(2) << day << ", " << setprecision(4) << year << endl;
}

void Date::printLongDMY()
{
	cout << setprecision(2) << day << " " << monthName(month) << " " << setprecision(4) << year << endl;
}

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

Date Date::operator++()
{

}
