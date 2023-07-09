#include <iostream>
using namespace std;
  
void incrementPointer(int* ptr)
{   
    *ptr += 1;
}
  
int main(void)
{
    const int val = 10;     // const value
    const int *ptr = &val;  // pointer to const val (must have const in front)
    incrementPointer( const_cast <int *>(ptr) );   // cast away constness
    cout << *ptr << '\n';
    return 0;
}