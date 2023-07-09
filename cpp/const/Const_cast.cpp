#include <iostream>
using namespace std;
  
void incrementPointer(int* ptr)
{   
    *ptr += 1;
}

class ConstCounter 
{
    int counter = 0;
public:
    void increaseCounter() const
    {
        cout << "This is a const method!\n";
        cout << "Old counter : "<< counter << '\n';
        (const_cast <ConstCounter*> (this))->counter += 1; 
        cout << "Increased counter by 1!\n";
        cout << "New counter : "<< counter << '\n';
        cout << "-----------------------\n";

    }
};
  
int main(void)
{
    const int val = 10;     // const value
    const int *ptr = &val;  // pointer to const val (must have const in front)
    //const int * const ptr = &val; // this works also with const pointer ro const val
    cout << "Pointer to const value before : " << *ptr << '\n';

    incrementPointer( const_cast <int *>(ptr) );   // cast away constness
    cout << "Pointer to const value after  : " << *ptr << '\n';

    cout << "---------\n";

    ConstCounter cc;
    for(int i = 0; i < 8; ++i)
        cc.increaseCounter();

    return 0;
}