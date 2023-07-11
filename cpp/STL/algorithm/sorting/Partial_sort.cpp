#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
std::ostream & operator << (std::ostream & strm, const std::vector<T> & vec)
{
    for (auto vec_element: vec)
        strm << vec_element << ", ";
    return strm;
}

int main( void )
{
    std::vector<int> vec = { 8, 6, 5, 7, 9, 4, 3, 2, 1 };

    std::cout << "unsorted:\n";
    std::cout << vec << '\n';

    // Partial Sort

    std::partial_sort( vec.begin(), vec.begin() + 4, vec.end() );
    // Sort first 4 (.begin() + 4) from begining to end of vec.


    std::cout << "partaly sorted (first four):\n";
    std::cout << vec << '\n';

    std::cout << "is sorted (begin - end) : ";
    std::cout << std::is_sorted( vec.begin(), vec.end() ) << '\n';

    std::cout << "is sorted (first four)  : ";    
    std::cout << std::is_sorted( vec.begin(), vec.begin() + 4 ) << '\n';
    
    // Ascending

    std::partial_sort( vec.begin(), vec.begin() + 4, vec.end(), std::greater<int>() );

    std::cout << "partal ascending sorted (first four):\n";
    std::cout << vec << '\n';

    std::cout << "is sorted ascending (begin - end) : ";
    std::cout << std::is_sorted( vec.begin(), vec.end(), std::greater<int>() ) << '\n';

    std::cout << "is sorted ascending (first four)  : ";    
    std::cout << std::is_sorted( vec.begin(), vec.begin() + 4, std::greater<int>() ) << '\n';
    

    return 0;
}
