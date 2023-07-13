#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> // adds ostream_iterator
#include <numeric>  // adds iota

// PRINT VECTOR OPTION 1

template <typename T>
std::ostream & operator << (std::ostream & strm, const std::vector<T> & vec)
{
    for ( size_t n = vec.size(); auto vec_element: vec )
        std::cout << vec_element << ( --n ? ", " : "" );
    return strm;
}


int main( void )
{
    std::vector<int> vec(10);
    std::iota( vec.begin(), vec.end(), 1 );

    // PRINT VECTOR OPTION 1'
    std::cout << vec << '\n';
    // print by overloading ostream<< operator

    // PRINT VECTOR OPTION 2
    for (size_t n = vec.size(); int i : vec )
        std::cout << i << ( --n ? ", " : "" );
    std::cout << '\n';
    // print by for loop

    // PRINT VECTOR OPTION 3
    std::copy( vec.begin(), vec.end(), std::ostream_iterator<int>( std::cout, ", " ) );
    // print by copying to ostream
    std::cout << '\n';

    {
        std::vector<int> temp( vec.size() );
        std::copy( vec.begin(), vec.end(), temp.rbegin() );
        std::move( temp.begin(), temp.end(), vec.begin() );
        // revers copy to temp and move it to origin
        std::cout << temp << '\n';
    }
    std::cout << vec << '\n';

    std::copy( vec.begin(), vec.end(), vec.rbegin() ); // vec --> { 10 9 8 7 6 6 7 8 9 10 }
    // try to copy itself in reverse
    std::cout << vec << '\n';

    {
        std::vector<int> temp;
        std::copy_if( vec.begin(), vec.end(), std::back_inserter(temp), [](int x) { return x % 2 == 0; } );
        // copy if element is even (divisible by two)
        std::cout << temp << '\n';
    }

    std::copy_if( vec.begin(), vec.end(), std::ostream_iterator<int>( std::cout, ", " ), [](int x) { return x < 8; } );
    // print copy of every element smaller then 8
    std::cout << '\n';
    std::cout << vec << '\n';

    {
        std::vector<int> temp;
        std::copy_if( vec.begin(), vec.end(), std::back_inserter(temp), [x = 1](int) mutable { ++x; return x % 2 == 0; } );
        // copy every seckond (strarting from first)
        std::cout << temp << '\n';
    }

    {
        std::vector<int> temp;
        std::copy_n( vec.begin(), 5, std::back_inserter(temp) );
        // copy first 5
        std::cout << temp << '\n';
    }
}
