#include <iostream>
#include <memory>

// Dog with virtual destructor implementation:

class Dog 
{
public:
    virtual ~Dog() { std::cout << "Dog deleted\n"; } 
};

class HuntingDog : public Dog
{
public:
    ~HuntingDog() { std::cout << "HuntingDog deleted\n"; }
};

class DogFactory
{
public:
    static Dog * createHuntingDog() { return new HuntingDog(); }
};

// SHARED POINTER VERSION:

class Dog_shptr
{
public:
    ~Dog_shptr() { std::cout << "Shared_ptr Dog deleted\n"; } // !!! NO VIRTUAL !!!
    // You can se how Dog_shptr destructor is not virtual BUT
    // becouse hunting dog will be created with SHARED PTR 
    // BOTH destructors (from Dog and HuntingDog) will be called

    // All STL classes does not have a virtual destructor
    // Be careful and try to use shared_ptr when writing classes inheriting from STL
};

class HuntingDog_shptr : public Dog_shptr
{
public:
    ~HuntingDog_shptr() { std::cout << "Shared_ptr HuntingDog deleted\n"; }
};

class DogFactory_shptr
{
public:
    static std::shared_ptr<Dog_shptr> createHuntingDog() 
    { 
        return  std::shared_ptr<HuntingDog_shptr>( new HuntingDog_shptr() ); 
    }
};

// end of shared pointer version

int main(int argc, char const *argv[])
{
    std::cout << "--------------------------------------------\n";
    std::cout << "HuntingDog created with regular new pointer:\n";
    std::cout << "------------------\n";
    Dog * dog_ptr = DogFactory::createHuntingDog();
    delete dog_ptr;

    std::cout << "---------------------------------------\n";
    std::cout << "HuntingDog created with shared pointer:\n";
    std::cout << "-----------------------------\n";
    {
        std::shared_ptr<Dog_shptr> dog_shptr =  DogFactory_shptr::createHuntingDog();
    }
    std::cout << "----------------------\n";
    return 0;
}
