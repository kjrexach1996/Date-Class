//Date.h - specification file for the Date class.

//****************
//* Date Formats *
//****************

//1. "MM/DD/YYYY" format will be represented by the name "monthFirst".
//2. "Month Day, Year" will be represented by the name "longForm".
//3. "Day Month Year" will be represented by the name "dayFirst".

#pragma once
#include <iostream>
using namespace std;

const int NUM_MONTHS = 12;

class Date
{
private:
	int month;
	int day;
	int year;
	static string months[NUM_MONTHS];
	int days[NUM_MONTHS];
public:

	//Accessor Functions

	//Preconditions: Function expects a value to exist in the month member, value must be an appropriate month value (1-12)
	//Postconditions: Function will return int value stored in month member
	int getMonthNum()
	{
		return month;
	}

	//Preconditions: Value must exist in month member, function must be able to access months[] array to access corresponding month name
	//Postconditions: Function will return the appropriate month name
	string getMonthName(int m)
	{
		return months[m];
	}

	//Preconditions: Value must exist in day member, value must be valid day value(1 - max.num of days in month)
	//Postconditions : Function will return int value stored in day member
	int getDay()
	{
		return day;
	}

	//Preconditions: Value must exist in year member, must be a positive number (< 1)
	//Postconditions: Function will return int value stored in year member
	int getYear()
	{
		return year;
	}

	//Mutator Function
	//Preconditions: Month, day, and year members must be accessible
	//Postconditions: Members will be updated with user parameters if all three values are valid; if at least one value is invalid, 
	//the function will automatically set the date to the default.Function will also display appropriate messages.If values are invalid,
	//the function will correctly examine each value and display a message if the value was invalid and the reasons for its invalidity.
	void setDate(int, int, int);

	//Checks if year is a leap year
	//Preconditions: Year member value must exist and be accessible through the setDate and initializeDays functions
	//Postconditions: Function will have calculated whether the year is a leap year or not by checking if the year is either divisible by 400 (1600, 2000, etc.) 
	//or if the year is both divisible by 4 and not divisible by 100 (this rules out any other century years since these years are not leap years.)
	bool isLeapYear(int);

	//Preconditions: Year member and days[] member must be accessible, function should expect isLeapYear function to work properly, result of isLeapYear function 
	//with year parameter inputted will determine the number of days assigned to Feb. (days[1])
	//Postconditions: Each index of days[] array will have the correct number of days in each month of the provided year, days[1] will either have 28 or 29 days 
	//depending on if the year is a leap year.
	void initializeDays(int);

	//Preconditions: Month member must be accessible, initializeDays function must have already been executed to correctly access the number of days 
	//of the provided month through the days[] member, function must access days[] member using "month - 1" to access the corresponding month index 
	//(If month = Jan., days[month - 1] = days[0])
	//Postconditions: Function will have returned the number of days in the month parameter
	int daysInMonth(int);

	//Preconditions: Function must receive a reference to another Date object in order to compare both objects' year, month, and day values
	//Postconditions: Function will determine which date comes before the other by comparing member values for both dates.The function will 
	//return "true" if the date calling the function comes first and "false" if the referenced date comes first.
	bool isEarlierThan(const Date&);

	//Preconditions: Month, day, and year members must be accessible and appropriate values, having gone through the setDate execution to confirm validity
	//Postconditions: Function will display the date represented by each int value next to the other separated with "/"
	void printMonthFirst();

	//Preconditions: Month, day, and year members must be accessible and appropriate values, having gone through the setDate execution to confirm validity, 
	//function should expect getMonthName and months[] array to be accessible using the correct parameter
	//Postconditions: Function will display the date showing the month name, day value, and year value
	void printLongForm();

	//Preconditions: Month, day, and year members must be accessible and appropriate values, having gone through the setDate execution to confirm validity,
	//function should expect getMonthName and months[] array to be accessible using the correct parameter
	//Postconditions : Function will display the date by showing the day value, month name, and year value
	void printDayFirst();

	//Overloaded operators

	//Preconditions: Day member must be accessible, daysInMonth function must work properly to access the max. number of days in the date's month member
	//to check if the day member is the last day of the month; date must be incremented then accessed
	//Postconditions: Day member will be incremented by one; if the day member is the last day of the month, day member will reset to 1 and month member
	//will increment by one(next month), if the month member is the last month of the year, year value will be increment by one(next year)
	Date operator++(); //prefix

	//Preconditions: Day member must be accessible, daysInMonth function must work properly to access the max. number of days in the date's month member
	//to check if the day member is the last day of the month; date must be accessed then incremented
	//Postconditions: Day member will be incremented by one; if the day member is the last day of the month, day member will reset to 1 and month member 
	//will increment by one(next month), if the month member is the last month of the year, year value will be increment by one(next year)
	Date operator++(int); //postfix

	//Preconditions: Day member must be accessible, daysInMonth function must work properly to access the max. number of days, day member must be set to 
	//the last day in previous month if the day is the first day of a month, month must be set to previous month if day is the first day of the month, 
	//year must be decremented by 1 if date is Jan. 1. If the date is Jan. 1, 1, the date cannon be decremented, and the date will reset to the default. Date must be incremented then accessed
	//Postconditions: Day member will be decremented by one; if day member is the first day of the month, day member will reset to the last day in the previous
	//month and month will decrement by one(previous month), if the month member is the first month of the year, year value will decrement by one(previous year)
	Date operator--(); //prefix

	//Preconditions: Day member must be accessible, daysInMonth function must work properly to access the max. number of days, day member must be set to 
	//the last day in previous month if the day is the first day of a month, month must be set to previous month if day is the first day of the month, 
	//year must be decremented by 1 if date is Jan. 1. If the date is Jan. 1, 1, the date cannon be decremented, and the date will reset to the default. Date must be accessed then incremented
	//Postconditions: Day member will be decremented by one; if day member is the first day of the month, day member will reset to the last day in the previous
	//month and month will decrement by one(previous month), if the month member is the first month of the year, year value will decrement by one(previous year)
	Date operator--(int); //postfix

	//Preconditions: Function must have access to both date objects with valid member values, function does not care about the order in which the dates are subtracted. 
	//The function expects isEarlierThan function to work properly and provide the date that comes before the other. Function will create local variables: 
	//numDays to track the total number of days, daysValueDifference to track the difference in day values, daysInBetweenDates to track number of days in between dates
	//without regard for the year (Feb 2 - Nov 10 = 281). Function expects isLeapYear to function and add appropriate number of days to numDays depending if year is a
	//leap year or not (366 or 365). Function must also consider the start date of the first date--if the date falls on a leap year and comes before Feb. 29,
	//the extra day must be handled correctly. Function will add a number of days according to the number of years, months, and days the dates are separated from each other.
	//All values will be added to numDays at the end of the function, and the absolute value of numDays will be returned.
	//Postconditions: Function will return the number of days in between two given dates, regardless of the order provided, without changing any of the two dates' members.
	int operator-(const Date&);

	//Preconditions: Date object reference must have appropriate values that fall under valid parameters, operator must also have access to daysInMonth function to check 
	//if day member falls under the correct parameters, the correct formatting must also be displayed.
	//Postconditions: The date will be displayed in Format 2. When used in conjunction with "operator>>", if the date entered by the user is not valid, 
	//the date will be set to the default, and this operator will display the default as a result.
	friend ostream& operator<<(ostream&, Date&);

	//Preconditions: Date must be entered in "M/D/YYYY" format, all values will be used as parameters by setDate, date object will be created if values are valid, 
	//default date will be created if invalid values are used.
	//Postconditions: Date containing either user parameters or default parameters will be created.
	friend istream& operator>>(istream&, Date&);

	//Constructors

	//Preconditions: setDate function must be accessible and functioning
	//Postconditions: Date will be created with appropriate default values
	Date();

	//Preconditions: Each value should stay within its proper boundaries(year <= 1, 1 <= month <= 12, 1 <= day <= max.number of days in month) for a date to be created with default values.
	//If any of these values falls out of bounds, the default values will be used instead.Date will be created using setDate
	//Postconditions: Date will be created with either user or default parameters
	Date(int, int, int);
};


