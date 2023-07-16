#pragma once

#include <iostream>
#include "Date.h"


std::ostream & operator << (std::ostream & ostr, const Date & date )
{
    ostr << date.day << "." << date.month.getMonthNumbr() << "." << date.year.getValue();
    return ostr;
}
