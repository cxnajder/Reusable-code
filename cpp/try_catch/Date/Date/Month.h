#pragma once
#include <string>



class Month
{
public:
    enum class MonthName {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Month(Month::MonthName n):m_name(n) {};
    Month(int);

    int getMonthNumbr() const { return static_cast<int>(m_name); }

private: 
    Month::MonthName m_name;
    bool isValid(int);

public:
    class Exception 
    {
        int invalid_month_num;
        public:
        Exception(int inv_m_num) : invalid_month_num(inv_m_num) {}
        std::string what();
    };


};



