// date.cpp
// Implementation of the Date class

#include "date.h"

Date Date::_default{1,Month::January,1900};

Date::Date(int dd,Month MM,int YYYY)
{
    _day={dd};_year={YYYY};_month={MM};
    //if a date according to the month
     if (dd>daysInMonth() || dd<1) throw InvalidDay();
     //Check if the year is negative
     else if (YYYY<0) throw InvalidYear();
	 
	 
}
//default constructor
Date::Date()
{
    _day = _default.day();
    _month = _default.month();
    _year = _default.year();
}
int Date::day() const
{
	return _day;
}

Month Date::month() const
{
    return _month;
}

int Date::year() const
{
	return _year;
}

bool Date::isLeapYear() const
{
    // leap years must be divisible by 4 but not by 100
    // or divisible by 400
    if(((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0))
        return true;
    else
        return false;
}

int Date::daysInMonth() const
{
	switch (_month) {
		case Month::January: 
		case Month::March: 
		case Month::May: 
		case Month::July:
		case Month::August: 
		case Month::October: 
		case Month::December:
			return 31;	
		case Month::April: 
		case Month::June: 
		case Month::September:
		case Month::November:
			return 30;	
		case Month::February:
			if ( isLeapYear() ) return 29;
			else return 28;
		default:
			// should never reach here 
			assert(false); // See: http://www.cplusplus.com/reference/cassert/assert/
            return -1;
	}    
}
bool Date::operator==(const Date& rhs) const
{
    if(_day == rhs.day() && _month == rhs.month() && _year==rhs.year())
        return true;
    else return false;
}
void Date::IncrementDate()
{
    if (_day+1<=daysInMonth())
        _day += 1;
    else if (_day+1>daysInMonth() && _month != Month::December){
        _day = 1;
		_month = static_cast<Month>(static_cast<int>(month()) + 1);
    }
    else if (_day+1>daysInMonth() && _month == Month::December){
        _day = 1;
		_month = Month::January;
        _year += 1;
    }
}
void Date::setDefaultDate(int day, Month month, int year)
{
//	Date _default{day,month,year};
	_default._day = day;
	_default._month = month;
	_default._year = year;
}
// Note, this standalone function is not part of the Date class
void printDate(const Date& date)
{
	cout << date.day() << "/"
		// cast to an integer to allow the month to be sent to the stream
        << static_cast<int>(date.month()) << "/"
		<< date.year()
		<< endl;
}

