#pragma once

#include "Month.h"
#include "Month.cpp"
#include "Year.h"
#include "Year.cpp"
#include <iostream>
#include <array>
#include <string>

class Date{
public:
    Date( int d, Month m, int y );
    friend std::ostream & operator << (std::ostream & ostr, const Date & date );
    bool isLeapYear();

private:
    int day;
    Month month;
    Year year;

    const std::array<int, 12> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:

    class Day 
    {
        public:
        class Exception
        {
            int invalid_day;
            int month;
            int year;
            public:
            Exception(int inv_d, int m, int y) : invalid_day(inv_d), month(m), year(y) {}
            std::string what();
        };
    };

};