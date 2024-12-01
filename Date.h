// Date.h, the specification file for the class Date

// Benjamin Hertzler
// CSC 222
// Date Class Project

#pragma once

#include <string>
#include <iostream>
using namespace std;

class Date
{
public:
	// Mutators
	
	// Function to set the date.
	// Postcondition: month = mm; day = dd; year = yyyy
	//		mm must be an int between 1 and 12;
	//		dd must be an int between 1 and the length of the month;
	//		yyyy must be a must be an int between 1 and 9999;
	void setDate(int mm, int dd, int yyyy);
	
	// Accessors

	// Function to return the date.
	// Postconditon: m = month; d = day; y = year
	void getDate(int& m, int& d, int& y);

	// Function to check if year y is a leap year.
	// Postcondition: Returns true if y is a leap year, otherwise false.
	bool isLeapYear(int y);

	// Function to return the length of month m.
	int monthLength(int m);

	// Function to return the name of month m.
	string monthName(int m);

	// Output

	// Function to print the date numerically.
	// Outputs in the format "MM/DD/YYYY"
	void printMDY();

	// Function to print the date descriptively.
	// Outputs in the format "[MONTH NAME] DD, YYYY"
	void printLongMDY();

	// Function to print the date descriptively.
	// Outputs in the format "DD [MONTH NAME] YYYY"
	void printLongDMY();


	// Operator Overloads

	Date operator++();
	Date operator++(int);
	Date operator--();
	Date operator--(int);
	friend ostream& operator<<(ostream&, Date&);
	friend istream& operator>>(istream&, Date&);

	// Constructors

	// Default Constructor.
	// Default Parameters: month = 1; day = 1; year = 1930
	Date() : month(1), day(1), year(1930) { setMonths; }

	// Overloaded Constructor.
	// Postcondition: month = mm; day = dd; year = yyyy;
	Date(int mm, int dd, int yyyy) { setDate(mm, dd, yyyy); }

private:
	int month;													// Variable to store the month
	int day;													// Variable to store the day
	int year;													// Variable to store the year
	struct monthType { string name; int length; };				// Struct to store month attributes
	monthType months[12];										// Array to store the months
	void setMonths();											// Private function to manage month attributes
};

