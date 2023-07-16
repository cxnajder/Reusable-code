#pragma once

#include "Month.h"
#include "Month.cpp"
#include "Year.h"
#include "Year.cpp"
#include <iostream>

class Date{
public:
    Date( int d, Month m, int y ) : day(d), month(m), year(y) {}
    friend std::ostream & operator << (std::ostream & ostr, const Date & date );
private:
    int day;
    Month month;
    Year year;
};