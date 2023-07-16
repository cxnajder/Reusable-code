#pragma once

#include "Month.h"
#include <sstream>


Month::Month(int m_number)
{
    if (isValid(m_number))
        m_name = static_cast<Month::MonthName>(m_number);
    else
        throw Exception(m_number);
}

bool Month::isValid(int m_number)
{
    return (m_number > 0 && m_number < 13);
}

std::string Month::Exception::what()
{
    std::stringstream ss;
    ss << "Invalid Month: " << invalid_month_num << " - not in valid range : 1-12";
    return ss.str();
}

