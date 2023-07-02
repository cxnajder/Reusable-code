#include <memory>

#include <string>
#include <iostream>

class DummyClass {
    static int unname_counter;
    bool unnamed;
    std::string name;
public:
    // special constructors created for testing
    DummyClass();
    DummyClass(std::string n); //: name(n) {std::cout<<name<<"has been created\n";}
    ~DummyClass();             //          {std::cout<<name<<"has been deleted\n";}
};

int DummyClass::unname_counter = 1;

DummyClass::DummyClass(){
    name = "[[unnamed pointer" + std::to_string(unname_counter) + "]]";
    unnamed = true;
    ++unname_counter;

    std::cout<<name<<" has been CREATED\n";
}

DummyClass::DummyClass(std::string n): name(n) {
    unnamed = false;
    std::cout<<name<<" has been CREATED\n";
}

DummyClass::~DummyClass() {
    if (unnamed)
        --unname_counter;
    std::cout<<name<<" has been DELETED\n";
}


int main(int argc, char const *argv[])
{
    std::cout<<"MAIN STARTS\n";
    //------------------------------------
    // STANDARD BASIC POINTERS 

    DummyClass * ptr1 = new DummyClass("<<basic pointer 1>>");
    DummyClass * ptr2 = new DummyClass("<<basic pointer 2>>");
    DummyClass * ptr_tab = new DummyClass[5];

    delete ptr1;    // has to be openly deleted to free memory
    delete ptr2;  // <-- COMMENTING THIS LINE WILL PREVENT ptr2 DESTRUCTOR FROM BEAING CALLED!!!
    delete [] ptr_tab; // easy to forget abut [] - IT'S MUCH EASIER AND SAFER TO JUST USE VECTORS!

    //------------------------------------
    // UNIQUE POINTER

    std::unique_ptr<DummyClass> uptr1 (new DummyClass("((unique pointer 1))"));
    std::unique_ptr<DummyClass> uptr2 = std::make_unique<DummyClass>("((unique pointer 2))");
    auto uptr3 = std::make_unique<DummyClass>("((unique pointer 3))");

    // this pointers will be deleted after exiting main automatically
    // uniq pointer is the only owner of dynamic object    
    // we can not copy this walue to a other pinter
    // unique pointer object can have only one owner

    // pl:
    // jest jedynym włascicielem nowego utworzonego (dynamicznego) obiektu
    // obiekt unique-pointera może mieć tylko jednego właściciela
    // nie możemy skopiowac adresu obiektu do innego pointera 

    //------------------------------------
    // SHARED POINTER

    std::shared_ptr<DummyClass> sptr1 (new DummyClass("{{shared pointer 1}}"));
    std::shared_ptr<DummyClass> sptr2 = std::make_shared<DummyClass>("{{shared pointer 2}}");
    auto sptr3 = std::make_shared<DummyClass>("{{shared pointer 3}}");
    std::shared_ptr<DummyClass> sptr4 = sptr1;
    // shared-pointer allows to share memory/object with other pointers
    // the memory will be released (destructor will be called) when the last pointer "disappears"
    // shared-poiter require extra memory cost to count numbers of pointers pointing object


    std::cout<<"MAIN ENDS\n";
    return 0;
}
