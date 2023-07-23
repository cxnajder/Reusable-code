#pragma once
#include "InvoiceSaver.h"
#include <iostream>

class InvoicePdfSaver : public InvoiceSaver
{
    public:
    void save(const Invoice & invoice) override
    {
        std::cout << "saveing to pdf file.\n";
    }
};
