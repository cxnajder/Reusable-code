#include <iostream>

class ConstTester {
    std::string name;
    mutable int getNameCounter = 0;
    int getCounterCounter = 0;
public:
    
    ConstTester() { name = "unnamed"; }

    void refMethod (int & a) {std::cout << "Ref method : " << a << '\n'; }
    void refMethod (const int & a) {std::cout << "const Ref method : " << a << '\n'; }

    void constTest () {std::cout << "Const test : not const\n"; }
    void constTest () const {std::cout << "Const test : const\n"; }

    const std::string & getName() const 
    {
        ++getNameCounter; 
        // becouse getNameCounter parameter is mutable this operation will be allowed even in const method
        return name; 
    } 

    int getCounter() const 
    {
        (const_cast <ConstTester*> (this))->getCounterCounter += 1; 
        // even though the method is const, const_cast allows to cast away the constness
        return getNameCounter; 
    }
    
    int getCounterCounterVal() const { return getCounterCounter; }
};

int main(int argc, char const *argv[])
{

    const int * ptr1 = new int;    // data is const, but ptr not
    int const * ptr2 = new int;    // the same
    //*ptr1 = 11; // <-- error: assignment of read-only location ‘* cptr1’
    //*ptr2 = 13; // same error -//-
    ++ptr1;
    --ptr1; // but its allowe to increment and decrement this pointer

    ++ptr2;
    --ptr2;
    
    delete ptr1;     
    delete ptr2; 

    int * const ptr3 = new int; // now ptr ins const but the value not;
    *ptr3 = 17;
    //++ptr3; // <-- error: increment of read-only variable ‘ptr3’
    //--ptr3;
    delete ptr3;

    const int * const ptr4 = new int; // const data and const ptr;
    //*ptr4 = 4; // <-- error: assignment of read-only location ‘*(const int*)ptr4’
    //++ptr4; // error
    //--ptr4; // error
    delete ptr4;

    ConstTester t1;

    int x = 20;
    t1.refMethod(x);    //20
    t1.refMethod(19);
    t1.refMethod(x-2);  // 18
    
    std::cout << '\n';

    t1.constTest();

    const ConstTester t2;
    t2.constTest();

    for(int i = 0; i < 5; ++i)
        std::cout << t1.getName() << " <-- t1 getName attem " << t1.getCounter() <<'\n';

    std::cout << "GetCounter fun called : " << t1.getCounterCounterVal() <<" times\n";
    std::cout << "--------------\n";

    for(int i = 0; i < 5; ++i)
        std::cout << t2.getName() << " <-- t1 getName attem " << t2.getCounter() <<'\n';

    std::cout << "GetCounter fun called : " << t2.getCounterCounterVal() <<" times\n";


    return 0;
}
