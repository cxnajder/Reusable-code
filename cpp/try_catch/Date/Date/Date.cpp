#pragma once

#include <iostream>
#include <sstream>
#include "Date.h"

Date::Date( int d, Month m, int y ) : month(m), year(y) 
{
    if (d > 0 && d <= monthDays[m.getMonthNumbr()-1])
        day = d;

    else if (m.getMonthNumbr() == 2 && d == 29 && isLeapYear())
        day = d;
    else
        throw Day::Exception(d, m.getMonthNumbr(), y);

}

std::ostream & operator << (std::ostream & ostr, const Date & date )
{
    ostr << date.day << "." << date.month.getMonthNumbr() << "." << date.year.getValue();
    return ostr;
}

bool Date::isLeapYear()
{
    const static int leapException    = 400;
    const static int nonLeapException = 100;

    return 
    (
        year.getValue() % 4 == 0 
        &&
        (
            year.getValue() % nonLeapException != 0 
            ||
            year.getValue() % leapException == 0
        )
    );
}

std::string Date::Day::Exception::what()
{
    std::stringstream ss;
    ss << "Invalid Day of Month: " << invalid_day << '.' << month << '.' << year;
    return ss.str();
}