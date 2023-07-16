#pragma once
#include <string>

class Year
{
public:
    Year(int val_);
    int getValue() const { return value; }
    
private:
    int value;
    static const int max_year = 2300;
    static const int min_year = 1800;
    
public:
    class Exception
    {   
        int invalid_year;
        public:
        Exception(int inv_y) : invalid_year(inv_y) {}
        std::string what();
    };
    bool isValid(int year_value);

    //friend class Date;
};
