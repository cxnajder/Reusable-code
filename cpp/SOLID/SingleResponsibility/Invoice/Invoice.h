#pragma once

#include <string>
#include <vector>

#include "InvoiceItem.h"

class Invoice
{
private:
    std::string vendor;
    std::string buyer;
    double total;
    std::vector<InvoiceItem> items;
public:
    Invoice(const std::vector<InvoiceItem> &, const std::string &, const std::string &);
    double calculate_total() const;

    //friend class InvoiceLogger;
    friend void invoiceLogger(Invoice &);
    friend void invoiceSaver(Invoice &);

    /*
        Single Responsibility rule says a class should focus only on the main purpouse.
        The purpouse of the Invoice class is to hold data (not to print in console and not to save to pdf).
        Which is why saveing and printing is done by outside friend functions.(but could be done by friend class too)
    
    */
};
