#ifndef DATE_H
#define DATE_H
// date.h
// class Date declaration

#include <cassert>
#include <iostream>
using namespace std;

//class InvalidDay{};
//class ThrowInvalidMonth{};
//class InvalidYear{};

enum class Month 
{
	January = 1, 
	February,
	March, 
	April,
	May,
	June,
	July, 
	August, 
	September,
	October,
	November, 
	December
};
	
class InvalidDay{};
class ThrowInvalidMonth{};
class InvalidYear{};

	
class Date
{
public:	
    Date(int dd,Month MM,int YYYY);
    Date ();
	// return the day of the month
	int	day () const;
	// return the month of the year
	Month month () const;
	// return the year
	int year () const;
	// return true if it is a leap-year, false if not
	bool isLeapYear () const;	
	
	bool operator==(const Date& rhs) const;
    //Increment the day by one and keep the date valid
    void IncrementDate();

    static void setDefaultDate(int day, Month month, int year);
private:
	// return the number of days in the _month
	int	daysInMonth () const;	
	
	int	_day;
	Month _month;
	int	_year;

	static Date _default;
};

// standalone function for printing the date
void printDate(const Date& date);

#endif