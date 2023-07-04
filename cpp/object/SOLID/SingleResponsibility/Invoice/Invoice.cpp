#pragma once

#include "Invoice.h"
#include <iostream>

Invoice::Invoice(
    std::vector<InvoiceItem> items_, 
    std::string vendor_,
    std::string buyer_
){
    vendor = vendor_;
    buyer = buyer_;
    items = items_;
    total = this->calculate_total();
}

double Invoice::calculate_total() const 
{
    double total = 0;
    for (auto item: items)
    {
        total += item.price * item.count * (1 + item.tax);
    }
    return total;
}


void invoiceLogger(Invoice & inv)
{
    std::cout << inv.vendor << '\n';
    std::cout << inv.buyer << '\n';
    std::cout << inv.total << '\n';
}

void invoiceSaver(Invoice & inv)
{

    std::cout << "saveing to pdf file.\n";
}

