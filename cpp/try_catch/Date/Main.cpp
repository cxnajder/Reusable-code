#include "Date/Date.h"
#include "Date/Date.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>


void printDate(const Date & date) {
    std::cout << date << '\n';
}


void tryCreateDate(int d, int m, int y)
{
    try
    {
        Date date( d, m, y);
        std::cout << "Success";
    }
    catch(Month::Exception e)
    {
        std::cerr << e.what();
    }
    catch(Year::Exception e)
    {
        std::cerr << e.what();
    }
    catch(Date::Day::Exception e)
    {
        std::cerr << e.what();
    }
    catch(...)
    {
        std::cerr << "Other exception during create-Date-test";
    }

}

void tryCreateDateVerbous(int d, int m, int y)
{
    std::cout << d << '.' << m << '.' << y << " test : ";
    tryCreateDate( d, m, y);
    std::cout << '\n';
}

void testMonthRange(int begin_month, int end_month)
{
    assert(begin_month <= end_month);

    int day = 1;
    int year = 2000;

    for(int month = begin_month; month <= end_month; ++month)
        tryCreateDateVerbous(day, month, year);
}

void testYearRange(int begin_year, int end_year)
{
    assert(begin_year <= end_year);

    int day = 1;
    int month = 1;

    for(int year = begin_year; year <= end_year; ++year)
        tryCreateDateVerbous(day, month, year);
}

void testDayRange(int begin_day, int end_day, int month = 1, int year = 2000)
{
    assert(begin_day <= end_day);

        for(int day = begin_day; day <= end_day; ++day)
        tryCreateDateVerbous(day, month, year);

}

int main()
{
    testMonthRange(-2, 14);
    testYearRange(1790, 1810);
    testYearRange(2290, 2310);
    testDayRange(-2, 31, 2, 2000);
    testDayRange(-2, 31, 2, 2001);

    return 0;
}
