#pragma once
#include "Invoice.h"

class Invoice;

class InvoiceSaver
{
public:
    virtual void save(const Invoice & invoice) = 0;
};




