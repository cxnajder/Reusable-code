#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::ostream & operator << (std::ostream & ostr, const std::vector<T> & vec)
{
    for(auto elem: vec)
        ostr << elem << ", ";
    return ostr;
}

int main( void )
{
    std::vector<int> vec = { 5, 7, 8, 9, 0, 1, -10, 10, -9, 8 };

    std::cout << "original vector:\n";
    std::cout << vec << '\n';

    std::sort( 
        vec.begin(), 
        vec.end(), 
        []( int a, int b ){ return a > b; } // <-- lambda
    );


    std::cout << "sorted vector:\n";

    std::for_each(
        vec.begin(), 
        vec.end(), 
        [](const int & x)
        {   // lambda that pirnts int number
            std::cout << x << ", ";
        }
    );
    std::cout << '\n';
    

    std::vector<int> oddNums;
    std::vector<int> evenNums;
    std::vector<int> negativeNums;

    auto findNegative = [&negativeNums] ( int x ){
        if( x < 0 )
            negativeNums.push_back(x);
    };

    auto findOddAndEven = [&] ( int x ){
        if( x % 2 == 0 )
            evenNums.push_back(x);
        else
            oddNums.push_back(x);
    };

    std::for_each( vec.begin(), vec.end(), findNegative );
    std::for_each( vec.begin(), vec.end(), findOddAndEven );
   

    std::cout << "negative numbers:\n";
    std::cout << negativeNums << '\n';
    
    std::cout << "even numbers:\n";
    std::cout << evenNums << '\n';

    std::cout << "odd numbers:\n";
    std::cout << oddNums << '\n';



    auto fixNegativeAndOdd = []( int & x ) -> void { 
        if( x < 0 )
            x *= -1;
        if( x % 2 == 1)
            ++x;
    };

    std::for_each( vec.begin(), vec.end(), fixNegativeAndOdd );
   
    std::cout << "fixed negative and odd numbes in vector:\n";
    std::cout << vec << '\n';
    
    return 0;
}
