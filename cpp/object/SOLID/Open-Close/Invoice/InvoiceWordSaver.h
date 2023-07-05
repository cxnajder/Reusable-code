#pragma once
#include "InvoiceSaver.h"
#include <iostream>

class InvoiceWordSaver : public InvoiceSaver
{
    public:
    void save(const Invoice & invoice) override
    {
        std::cout << "saveing to word file.\n";
    }
};