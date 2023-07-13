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

    // PRINT VECTOR OPTION 2
    for (size_t n = vec.size(); int i : vec )
        std::cout << i << ( --n ? ", " : "" );
    std::cout << '\n';

    // PRINT VECTOR OPTION 3
    std::copy( vec.begin(), vec.end(), std::ostream_iterator<int>( std::cout, ", " ) );
    std::cout << '\n';

    {
        std::vector<int> temp( vec.size() );
        std::copy( vec.begin(), vec.end(), temp.rbegin() );
        std::move( temp.begin(), temp.end(), vec.begin() );

        std::cout << temp << '\n';
    }
    std::cout << vec << '\n';

    std::copy( vec.begin(), vec.end(), vec.rbegin() ); // vec --> { 10 9 8 7 6 6 7 8 9 10 }
    std::cout << vec << '\n';

}
