#pragma once

#include "Invoice.h"
#include "InvoiceSaver.h"
#include <iostream>

Invoice::Invoice(
    const std::vector<InvoiceItem> & items_, 
    const std::string & vendor_,
    const std::string & buyer_
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

// friend functions: 

void invoiceLogger(Invoice & inv)
{
    std::cout << inv.vendor << '\n';
    std::cout << inv.buyer << '\n';
    std::cout << inv.total << '\n';
}

void invoiceSaver(const Invoice & inv, InvoiceSaver * invoice_saver)  
// for some reason i couldnt paste InvoiceSaver & invoice_saver here
{
    invoice_saver->save(inv); // Liskov Substitution
}

