#include "Invoice.h"

#include "Invoice.cpp"   // for some reason g++ requires .cpp files included as well

#include "InvoiceSaver.h"
#include "InvoicePdfSaver.h"
#include "InvoiceWordSaver.h"

#include <vector>
#include <iostream>

int main()
{
    std::vector<InvoiceItem> inv_items;
    inv_items.push_back(InvoiceItem{"Pen", 0.87, 5, 0.15});             //  =  5.0025
    inv_items.push_back(InvoiceItem{"Paper sheet", 0.03, 10, 0.15});    //  =  0.345
    inv_items.push_back(InvoiceItem{"coffee", 4.75, 1, 0.20});          //  =  5.7
    //                                                           total  = 11.0475
    
    Invoice invoice(inv_items, "shop", "me");

    invoiceLogger(invoice);


    InvoicePdfSaver pdf_saver;
    InvoiceWordSaver wrd_saver;

    invoiceSaver(invoice, &pdf_saver);  // <- This is also example of Liskov Substitution
    invoiceSaver(invoice, &wrd_saver);  // Liskov



    InvoiceSaver * inv_saver;

    inv_saver = &pdf_saver;
    inv_saver->save(invoice);   // Liskov

    inv_saver = &wrd_saver;
    inv_saver->save(invoice);   // Liskov


    return 0;
}
