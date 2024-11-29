// Date.cpp - implementation file for the Date class.

#include <iostream>
#include "Date.h"
using namespace std;

string Date::months[NUM_MONTHS] =
{
	"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
};

Date::Date()
{
	//Date set to default values
	setDate(1, 1, 1930);
}

Date::Date(int m, int d, int y)
{
	//Date set to user parameters if valid
	setDate(m, d, y);
}

void Date::setDate(int m, int d, int y)
{
	//Adds correct number of days to each month of the year; leap year status is checked to add correct days to Feb.
	initializeDays(y);

	//All values are stored in members if all are valid
	if (y >= 1 && (1 <= m && m <= 12) && (1 <= d && d <= daysInMonth(m)))
	{
		month = m;
		day = d;
		year = y;
	}
	else
	{
		//Prints if one or more values is invalid
		cout << "ERROR! Date entered is not a valid date. Reason(s): " << endl;
		
		//If month is invalid
		if (m < 1 || 12 < m)
		{
			cout << "Invalid month value: " << m << endl;
			if (m < 1)
				cout << "Month value cannot be less than 1." << endl;
			else
				cout << "A year only has 12 months." << endl;
		}

		//If day is invalid
		if (d < 1 || daysInMonth(m) < d)
		{
			cout << "Invalid day value: " << d << endl;
			if (d < 1)
				cout << "Day value cannot be less than 1." << endl;
			else if (1 <= m && m <= 12)
			{
				if (d > daysInMonth(m))
					cout << "There are only " << daysInMonth(m) << " days in the month of " << months[m - 1] << "." << endl;
			}
			else
				cout << "There are no months with more than 31 days." << endl;
		}

		//If year is invalid
		if (y < 1)
		{
			cout << "Invalid year value: " << y << endl;
			cout << "Year value cannot be less than 1." << endl;
		}
		cout << "Setting date to default: January 1, 1930" << endl;

		//Date is set to default
		month = 1;
		day = 1;
		year = 1930;
	}
	
}

bool Date::isLeapYear(int year)
{
	//Checks if year is a leap year
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	return false;
}

void Date::initializeDays(int year)
{
	//Adds number of days to all months of the year
	days[0] = 31; days[2] = 31; days[3] = 30;
	days[4] = 31; days[5] = 30; days[6] = 31;
	days[7] = 31; days[8] = 30; days[9] = 31;
	days[10] = 30; days[11] = 31;

	//If the year is a leap year, Feb. gets 29 days, 28 otherwise
	if (isLeapYear(year))
		days[1] = 29;
	else
		days[1] = 28;
		
}

int Date::daysInMonth(int month)
{
	//Returns the number of days in a month
	return days[month - 1];
}

bool Date::isEarlierThan(const Date& date)
{
	//Checks to see if one date comes before the other date
	//Checks year first. If the years are the same, it checks months
	//If the months are the same, it checks days. 
	//If the days are the same or the first day is greater, the first date does
	//not come before the second, and the function returns false.

	if (year < date.year)
	{
		return true;
	}
	else if (year == date.year)
	{
		if (month < date.month)
		{
			return true;
		}
		else if (month == date.month)
		{
			if (day < date.day)
				return true;
		}
	}
	return false;
}

void Date::printMonthFirst()
{
	//Prints date in MM/DD/YYYY format
	cout << month << "/" << day << "/" << year << endl;
}

void Date::printLongForm()
{
	//Prints date in Month Day, Year format
	cout << getMonthName(month - 1) << " " << day << ", " << year << endl;
}

void Date::printDayFirst()
{
	//Prints date in Day Month Year format
	cout << day << " " << getMonthName(month - 1) << " " << year << endl;
}

Date Date::operator++()
{
	//Prefix operator
	//Increments the day member by one. If the day is the last day of the month, 
	//day becomes 1 and month increments. If the month is the last month of the year,
	//month becomes 1 and year increments.
	//Object must be incremented then accessed.

	if (day == daysInMonth(month))
	{
		day = 1;

		if (month == NUM_MONTHS)
		{
			month = 1;
			year++;
		}
		else
			month++;
	}
	else
		day++;

	return *this;
}

Date Date::operator++(int i)
{
	//Postfix operator
	//Increments the day member by one. If the day is the last day of the month, 
	//day becomes 1 and month increments. If day is the last day of the year 
	//and the month is the last month of the year, month and day become 1 and year increments.
	//Object must be accessed then incremented.

	Date temp = *this;

	if (day == daysInMonth(month))
	{
		day = 1;

		if (month == NUM_MONTHS)
		{
			month = 1;
			year++;
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
	//Prefix operator
	//Decrements day member by one. If the day is the first day of the month, 
	//day becomes the last day of the previous month, and month decrements.
	//If month is 1 and day is one, day becomes the last day in Dec. and month becomes Dec.
	//Year decrements.
	//*** If all three members are 1, date cannot decrement further, and date will reset to default. ***//
	//Object must be decremented then accessed.

	if (day == 1)
	{
		if (month == 1)
		{
			if (year == 1)
			{
				cout << "ERROR! Cannot decrement date any further: January 1, 1" << endl
					 << "Setting date to default: January 1, 1930" << endl;
				setDate(1, 1, 1930);
			}
			else
			{
				day = daysInMonth(NUM_MONTHS);
				month = NUM_MONTHS;
				year--;
			}
		}
		else
		{
			day = daysInMonth(month - 1);
			month--;
		}
	}
	else
		day--;

	return *this;
}

Date Date::operator--(int i)
{
	//Prefix operator
	//Decrements day member by one. If the day is the first day of the month, 
	//day becomes the last day of the previous month, and month decrements.
	//If month is 1 and day is one, day becomes the last day in Dec. and month becomes Dec.
	//Year decrements.
	//*** If all three members are 1, date cannot decrement further, and date will reset to default. ***//
	//Object must be accessed then decremented.

	Date temp = *this;

	if (day == 1)
	{
		if (month == 1)
		{
			if (year == 1)
			{
				cout << "ERROR! Cannot decrement date any further: January 1, 1" << endl
				     << "Setting date to default: January 1, 1930" << endl;
				setDate(1, 1, 1930);
			}
			else
			{
				day = daysInMonth(NUM_MONTHS);
				month = NUM_MONTHS;
				year--;
			}
		}
		else
		{
			day = daysInMonth(month - 1);
			month--;
		}
	}
	else
		day--;

	return temp;
}

int Date::operator-(const Date& date)
{
	//Operator will find the number of days in between two dates.
	
	//***Function will find the number of days NO MATTER the order the dates are received.***

	//Date1 and Date2 will be determined through IsEarlierThan. Date1 will become the earlier date
	Date date1;
	Date date2;

	//*this is saved to a placeholder variable to not directly access and change members
	Date tempDate = *this;

	//total number of days
	int numDays = 0;

	//days in between dates (excluding month and year)
	int daysValueDifference = 0;

	//days in between dates(excluding year)
	int daysInBetweenDates = 0;

	//If all three members of each date are the same, operator returns 0
	if ((year == date.year) && (month == date.month) && (day == date.day))
		return numDays;

	//Assigns earlier date to date1 and later date to date2
	if (tempDate.isEarlierThan(date))
	{
		date1 = tempDate;
		date2 = date;
	}
	else
	{
		date1 = date;
		date2 = tempDate;
	}

	//Finds difference in between day members
	daysValueDifference = date1.day - date2.day;
	if (daysValueDifference < 0)
		daysValueDifference *= -1;

	//***From this point, the operator is starting from date1 and counting days until it reaches date2.***

	//Date1's year is checked first. Days are added depending where the date lies on this first year.
	//If the beginning date lies on a leap year and lies on or before Feb. 29, an extra day must be included in the total.
	//If the end date lies on a leap year and lies on or after Feb. 29, an extra date must be included in the total.
	if (date1.year != date2.year)
		{
		//Beginning date
		if (isLeapYear(date1.year) && (date1.month < 2 || (date1.month == 2 && date1.day <= 29)))
			numDays += 366;
		else
			numDays += 365;
		//End date
		if (isLeapYear(date2.year) && (date2.month > 2 || (date2.month == 2 && date2.day == 29)))
			numDays += 1;
		}
	
	//Count continues from the next year going forward until the years match.
	for (int k = date1.year + 1; k < date2.year; k++)
	{
		if (isLeapYear(k))
			numDays += 366;
		else
			numDays += 365;
	}

	//Operator now checks if date1's month comes before or after date2's month.
	//If before, for loop increments from date1.month to date2.month, adding all days of every month to daysInBetweenDates.
	//If after, for loop decrements from date1.month to date2.month, adding all days of every month - 1 to daysInBetweenDates.
	//After the months match, the operator checks which day comes before the other and must account for
	//whether those days (daysValueDifference) should be added or subtracted from the total. 

	//Before
	if (date1.month < date2.month)
	{

		for (int i = date1.month; i < date2.month; i++)
		{
			//Days in each month are being added
			daysInBetweenDates += daysInMonth(i);
		}
		//Final days are added
		if (date1.day > date2.day)
			daysInBetweenDates -= daysValueDifference;
		else
			daysInBetweenDates += daysValueDifference;
	//After
	}
	else
	{
		for (int j = date1.month; j > date2.month; j--)
		{
			//Days in each month are being added
			daysInBetweenDates += daysInMonth(j - 1);
		}
		//Final days are added
		if (date1.day > date2.day)
			daysInBetweenDates += daysValueDifference;
		else
			daysInBetweenDates -= daysValueDifference;
	}
	
	//Lastly, numDays contains the number of days that have been kept track of per year, while
	//daysInBetweenDates has kept track of how many days there are between the dates, excluding the years.
	//The operator makes final comparisons between the dates' months and days to determine whether these days
	//(daysInBetweenDates) should be added or subtracted from the total.
	if (date1.month < date2.month)
		numDays += daysInBetweenDates;
	else if (date1.month > date2.month)
		numDays -= daysInBetweenDates;
	else
	{
		if (date1.day < date2.day)
			numDays += daysInBetweenDates;
		else
			numDays -= daysInBetweenDates;
	}
	//The absolute value is calculated and returned if needed.
	if (numDays < 0)
		numDays *= -1;

	return numDays;
}

ostream& operator<<(ostream& strm, Date& obj)
{
	//Operator displays the values of the date object in 
	//Month Day, Year format. 

	if (1 <= obj.month && obj.month <= 12)
		strm << obj.months[obj.month - 1];
	strm << " ";

	if (1 <= obj.day || obj.day <= obj.daysInMonth(obj.month))
		strm << obj.day;
	strm << ", ";

	if (obj.year >= 1)
		strm << obj.year;

	return strm;
}

istream& operator>>(istream& strm, Date& obj)
{
	//Operator processes a user inputted date in the form
	//"M/D/YYYY" and store each value in the proper member.
	//As these members are passed into setDate, if any of the values
	//are invalid, the default date is created.

	char ch;

	strm >> obj.month;
	strm.get(ch);
	strm >> obj.day;
	strm.get(ch);
	strm >> obj.year;

	obj.setDate(obj.month, obj.day, obj.year);
	return strm;
}

	