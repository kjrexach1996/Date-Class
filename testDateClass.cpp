//Date Class
//The purpose of this class is to represent any date in a given year.
//All years except leap years will contain 365 days; leap years will contain 366 days.
//During leap years, an additional day will be added to the month of February.
//Dates will be printed in the following formats:

// MM/DD/YYYY
// Month Day, Year
// Day Month Year

#include "Date.h"

int main()
{
	//Test default constructor
	cout << "Creating a date object with the default constructor and displaying using Format 1" << endl;
	Date defaultDate;
	defaultDate.printMonthFirst();
	cout << endl;

	//Test user parameter constructor
	cout << "Creating a date object with parameters and displaing using Format 2" << endl;
	Date givenDate(7, 4, 1776);
	givenDate.printLongForm();
	cout << endl;

	//Testing setDate function
	cout << "Changing date object using setDate() function and displaying using Format 3" << endl;
	givenDate.setDate(12, 25, 2024);
	givenDate.printDayFirst();
	cout << endl;

	//Testing for invalid dates
	cout << "Changing date object using setDate() function to 13/45/2018 for verification that it will not be accepted" << endl;
	givenDate.setDate(13, 45, 2018);
	givenDate.printLongForm();
	cout << endl;

	cout << "Changing date object using setDate() function to 4/31/2000 for verification that it will not be accepted" << endl;
	givenDate.setDate(4, 31, 2000);
	givenDate.printLongForm();
	cout << endl;

	cout << "Changing date object using setDate() function to 2/29/2009 for verification that it will not be accepted" << endl;
	givenDate.setDate(2, 29, 2009);
	givenDate.printLongForm();
	cout << endl;

	//Testing subtraction operator to find the days in between dates
	cout << "Setting one date to 4/10/2014 and another date to 4/18/2014 and subtracting the second from the first" << endl;
	Date firstDate(4, 10, 2014);
	Date secondDate(4, 18, 2014);
	int numDays = firstDate - secondDate;
	cout << "Number of days: " << numDays << endl << endl;

	cout << "Setting one date to 2/2/2006 and another date to 11/10/2003 and subtracting the second from the first" << endl;
	firstDate.setDate(2, 2, 2006);
	secondDate.setDate(11, 10, 2003);
	numDays = firstDate - secondDate;
	cout << "Number of days: " << numDays << endl << endl;

	//Testing pre- and post-increment and decrement operators
	cout << "Setting date to 2/29/2008 and using the pre-decrement operator to display previous day (2/28/2008)" << endl;
	givenDate.setDate(2, 29, 2008);
	--givenDate;
	givenDate.printLongForm();
	cout << endl;

	cout << "Using the pre-increment operator to display next day (2/29/2008)" << endl;
	++givenDate;
	givenDate.printLongForm();
	cout << endl;

	cout << "Setting date to 2/29/2008 and using the post-decrement operator to display previous day (2/28/2008)" << endl;
	givenDate.setDate(2, 29, 2008);
	givenDate--;
	givenDate.printLongForm();
	cout << endl;

	cout << "Using the post-increment operator to display next day (2/29/2008)" << endl;
	givenDate++;
	givenDate.printLongForm();
	cout << endl;

	cout << "Setting date to 12/31/2024 and using the post-increment operator to display next day (1/1/2025)" << endl;
	givenDate.setDate(12, 31, 2024);
	givenDate++;
	givenDate.printMonthFirst();
	cout << endl;

	cout << "Using the post-decrement operator to display previous day (12/31/2024)" << endl;
	givenDate--;
	givenDate.printMonthFirst();
	cout << endl;

	cout << "Setting date to 12/31/2024 and using the pre-increment operator to display next day (1/1/2025)" << endl;
	givenDate.setDate(12, 31, 2024);
	++givenDate;
	givenDate.printMonthFirst();
	cout << endl;

	cout << "Using the pre-decrement operator to display previous day (12/31/2024)" << endl;
	--givenDate;
	givenDate.printMonthFirst();
	cout << endl;

	//Testing stream insertion and stream extraction operators
	Date userDate;

	//User entered date with valid values (5/4/2016)
	cout << "Please enter a valid date in the form M/D/YYYY: ";
	cin >> userDate;
	cout << userDate;
	cout << endl << endl;

	//User entered date with invalid values (14/36/2017)
	cout << "Please enter an invalid date in the form M/D/YYYY: ";
	cin >> userDate;
	cout << userDate;
	cout << endl << endl;
}