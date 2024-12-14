// test-client.cpp; this program contains the main() function.
//

// Benjamin Hertzler
// CSC 222
// Date Class Project
//

#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//	1

	Date default_date;
	int temp_m, temp_d, temp_y;
	cout << "Default Date: ";
	default_date.print(1);

	//	2

	cout << "Enter a Month Number in Format MM: ";
	cin >> temp_m;
	cout << "Enter a Day Number in Format DD: ";
	cin >> temp_d;
	cout << "Enter a Year Number in Format YYYY: ";
	cin >> temp_y;
	Date user_date(temp_m, temp_d, temp_y);
	cout << "Your Date: ";
	user_date.print(2);

	//	3

	default_date.setDate(2, 29, 2008);
	cout << "Value of date 2/29/2008: ";
	default_date.print(3);

	//	4

	default_date.setDate(13, 45, 2018);
	cout << "Value of date 13/45/2018: ";
	default_date.print(3);

	//	5

	default_date.setDate(4, 31, 2000);
	cout << "Value of date 4/31/2000: ";
	default_date.print(3);

	//	6

	default_date.setDate(2, 29, 2009);
	cout << "Value of date 2/29/2009: ";
	default_date.print(3);

	//	7

	default_date.setDate(4, 10, 2014);
	user_date.setDate(4, 18, 2014);
	cout << "4/10/2024 - 4/18/2024 = " << default_date - user_date << endl;

	//	8

	default_date.setDate(2, 2, 2006);
	user_date.setDate(11, 10, 2003);
	cout << "2/2/2006 - 11/10/2003 = " << default_date - user_date << endl;

	//	9

	default_date.setDate(2, 29, 2008);
	++default_date;
	cout << "2/29/2008 Pre-Incremented: ";
	default_date.print(1);

	//	10

	--default_date;
	cout << "Pre-Decremented Back to Original: ";
	default_date.print(1);

	//	11

	default_date++;
	cout << "Post-Incremented: ";
	default_date.print(1);
	default_date--;
	cout << "Post-Decremented: ";
	default_date.print(1);

	//	12

	default_date.setDate(12, 31, 2024);
	default_date++;
	cout << "12/31/2024 Post-Incremented: ";
	default_date.print(1);

	//	13

	default_date--;
	cout << "Post-Decremented Back to Original: ";
	default_date.print(1);

	//	14

	++default_date;
	cout << "Pre-Incremented: ";
	default_date.print(1);
	--default_date;
	cout << "Pre-Decremented: ";
	default_date.print(1);

	//	15

	cout << "Enter a date in MM DD YYYY format, separated by whitespace: ";
	cin >> user_date;

	//	16

	cout << "Entered Date: " << user_date;

	return 0;
}