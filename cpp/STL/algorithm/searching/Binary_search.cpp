#include <iostream>
#include <vector>
#include <algorithm>

int main( void )
{
    std::vector<int> vec = { 1, 5, 6, 2, 11, 8 };

    std::sort(vec.begin(), vec.end() ); 
    // To make binary search work properly - vec must be sorted first!


    for (size_t n = vec.size(); int i : vec )
        std::cout << i << ( --n ? ", " : "" );
    std::cout << '\n';



    while(std::cin)
    {
        static int x;
        try {
            std::cout << "Check a number : ";
            std::cin >> x;
            if( std::binary_search( vec.begin(), vec.end(), x ) )
                std::cout << "Found : " << x << '\n';
            else
                std::cout << x<< " not found\n";

        }
        catch (...) {
            return -1;
        }
    }
}

/*
    Binary search is much faster then other searching methods
*/