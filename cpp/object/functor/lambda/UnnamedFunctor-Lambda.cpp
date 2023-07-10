#include <iostream>
#include <vector>
#include <algorithm>

int main( void )
{
    std::vector<int> vec = { 5, 7, 8, 9, 0, 1, -100, 100, -9, 8 };

    for ( int i: vec )
        std::cout << i << ", ";
    std::cout << '\n';

    std::sort( 
        vec.begin(), 
        vec.end(), 
        []( int a, int b ){ return a > b; } // <-- lambda
    );


    for ( int i: vec )
        std::cout << i << ", ";
    std::cout << '\n';
    
    return 0;
}
