#include <iostream>

class Test {
public:

    void refMethod (int & a) {std::cout << "Ref method : " << a << '\n'; }
    void refMethod (const int & a) {std::cout << "Ref method:" << a << '\n'; }

    void constTest () {std::cout << "Const test : not const\n"; }
    void constTest () const {std::cout << "Const test : const\n"; }
    
};

int main(int argc, char const *argv[])
{
    Test t1;

    int x = 20;
    t1.refMethod(x);    //20
    t1.refMethod(19);
    t1.refMethod(x-2);  // 18
    
    std::cout << '\n';

    t1.constTest();

    const Test t2;
    t2.constTest();

    return 0;
}
