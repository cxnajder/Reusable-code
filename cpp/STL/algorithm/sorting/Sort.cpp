#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

#include <chrono>

template <typename T>
std::ostream & operator << (std::ostream & strm, const std::vector<T> & vec)
{
    for (auto vec_element: vec)
        strm << vec_element << ", ";
    return strm;
}

int main( void )
{
    std::vector<int> vec1 = {
        100,1,2,1,3,4,5,6,700,999,89,5,1,
        10,89,4,3,23,76,42,-99,-1,101,20,
        90,55,6,2,3,32,333,-3,-665,22,-22,
        100,1,2,1,3,4,5,6,700,999,89,5,1,
        10,89,4,3,23,76,42,-99,-1,101,20,
        90,55,6,2,3,32,333,-3,-665,22,-22,
        100,1,2,1,3,4,5,6,700,999,89,5,1,
        10,89,4,3,23,76,42,-99,-1,101,20,
        90,55,6,2,3,32,333,-3,-665,22,-22,
    };

    std::vector<int> vec2 = vec1;

    std::cout << "Vector before sorting regularly:\n";
    std::cout << vec1 << '\n';

    auto startTime = std::chrono::high_resolution_clock::now();

    std::sort(vec1.begin(), vec1.end());    // Regural sorting algorithm
    
    auto stopTime = std::chrono::high_resolution_clock::now();

    std::cout << "Vector after sorting regularly:\n";
    std::cout << vec1 << '\n';

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
    std::cout << "Time spent : " << duration.count() << " micro sec" << '\n';

    std::cout << '\n';

    std::cout << "Vector before sorting parallel:\n";
    std::cout << vec2 << '\n';

    startTime = std::chrono::high_resolution_clock::now();

    std::sort(std::execution::par, vec2.begin(), vec2.end());
    // Sorting algorithm executed in parallel (execution::par)

    stopTime = std::chrono::high_resolution_clock::now();

    std::cout << "Vector after sorting in parallel:\n";
    std::cout << vec2 << '\n';

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
    std::cout << "Time spent : " << duration.count() << " micro sec" << '\n';
  

    return 0;
}
