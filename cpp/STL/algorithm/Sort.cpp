#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

template <typename T>
std::ostream & operator << (std::ostream & strm, const std::vector<T> & vec)
{
    for (auto vec_element: vec)
        strm << vec_element << ", ";
    return strm;
}

int main( void )
{
    std::vector<int> vec = {
        100,1,2,1,3,4,5,6,700,999,89,5,1,
        10,89,4,3,23,76,42,-99,-1,101,20,
        90,55,6,2,3,32,333,-3,-665,22,-22
    };

    std::cout << "Vector before sorting:\n";
    std::cout << vec << '\n';

    //std::sort(vec.begin(), vec.end());    // Regural sorting algorithm
    std::sort(std::execution::par, vec.begin(), vec.end());
    // Sorting algorithm executed in parallel (execution::par)

    std::cout << "Vector after sorting:\n";
    std::cout << vec << '\n';
  

    return 0;
}
