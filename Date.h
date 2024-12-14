// Date.h, the specification file for the class Date

// Benjamin Hertzler
// CSC 222
// Date Class Project

#pragma once

#include <string>
#include <iostream>
using namespace std;

// Class to manage a Date object including a month, day, and year.
class Date
{
public:
	// Mutators
	
	// Function to set the date.
	// Postcondition:	month = mm; day = dd; year = yyyy
	//		mm must be an int between 1 and 12;
	//		dd must be an int between 1 and the length of the month;
	//		yyyy must be a must be an int between 1 and 9999;
	void setDate(int mm, int dd, int yyyy);
	
	// Accessors

	// Function to return the date.
	// Postconditon: m = month; d = day; y = year
	void getDate(int& m, int& d, int& y) const;

	// Function to check if year y is a leap year.
	// Postcondition: Returns true if y is a leap year, otherwise false.
	bool isLeapYear(int y) const;

	// Function to return the length of month m.
	int monthLength(int m) const;

	// Function to return the name of month m.
	string monthName(int m) const;

	// Output

	// Function to output the date int format of the input parameter.
	// Precondition: format must be an int between 1 and 3
	// Postcondition:	Format 1: MM/DD/YYYY
	//		Format 2: [MONTH NAME] DD, YYYY
	//		Format 3: DD [MONTH NAME] YYYY
	//		Other format values: Outputs error message
	void print(int format);

	// Operator Overloads

	// Prefix ++ operator			
	Date operator++();

	// Postfix ++ operator
	Date operator++(int);

	// Prefix -- operator
	Date operator--();

	// Postfix -- operator
	Date operator--(int);

	// Overloaded subtraction operator (-)
	// Postcondition:	returns the number of days between the dates subtracted.
	int operator-(const Date&) const;

	// Overloaded stream insertion operator (<<)
	// Postcondition:	Outputs in the format "[MONTH] DD, YYYY ", does not end line by default.
	friend ostream& operator<<(ostream&, Date&);

	// Overloaded stream extraction operator (>>)
	// Precondition:	Date must be entered as 3 whitespace separated integers in the format m d y.
	// Postcondition:	cin >> date.month >> date.day >> date.year
	friend istream& operator>>(istream&, Date&);

	// Constructors

	// Default Constructor.
	// Default Parameters: month = 1; day = 1; year = 1930
	Date() : month(1), day(1), year(1930) { setMonths(); }

	// Overloaded Constructor.
	// Postcondition:	month = mm; day = dd; year = yyyy;
	//		mm must be an int between 1 and 12;
	//		dd must be an int between 1 and the length of the month;
	//		yyyy must be a must be an int between 1 and 9999;
	Date(int mm, int dd, int yyyy) { setDate(mm, dd, yyyy); }

private:
	int month;													// Variable to store the month
	int day;													// Variable to store the day
	int year;													// Variable to store the year
	struct monthType { string name; int length; };				// Struct to store month attributes
	monthType months[12];										// Array to store the months
	void setMonths();											// Private function to manage month attributes
	int julian() const;											// Private function to return the Julian Day Number
};

