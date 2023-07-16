#pragma once

#include "Year.h"
#include <sstream>

Year::Year(int val_)
{
    if ( isValid(val_) )
        this->value = val_;
    else
        throw Exception(val_);
}


bool Year::isValid(int year_value){
    return ( year_value > min_year && year_value < max_year );
}

std::string Year::Exception::what()
{
    std::stringstream ss;
    ss << "Invalid Year: " << invalid_year << " - not in valid range : " << min_year << "-" << max_year;
    return ss.str();
}