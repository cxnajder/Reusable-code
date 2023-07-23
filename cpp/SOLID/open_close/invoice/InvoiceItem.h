#pragma once

#include <string>

struct InvoiceItem
{
    std::string name;
    double price;
    int count;
    double tax;
};
