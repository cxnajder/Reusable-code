#include <iostream>

class Dog 
{
public:
    Dog() { std::cout << "Dog born\n"; bark(); }
    virtual ~Dog() { std::cout << "Dog deleted\n"; bark(); }
    virtual void bark() {  std::cout << "woof\n"; }
};

class HuntingDog : public Dog
{
public:
    HuntingDog() { std::cout << "HuntingDog born\n"; bark(); }
    ~HuntingDog() { std::cout << "HuntingDog deleted\n"; bark(); }
    void bark() {  std::cout << "WOOF\n"; }
};

int main(void)
{
    HuntingDog Hektor;
    return 0;
}

/*
    This fragment of code presents the order od constructors/destructors and virtual function calling from constructors/destructors in inheriting class
*/