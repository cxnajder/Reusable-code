#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = { 8, 45, 3, 2, 1, 6, 7, 99, -99 };
    /*
        nth_element(vec.begin(), vec.begin() + n, vec.end());

        Where n is the n-th number we are looking for (n'th smallest number)
        and it will be assigned at n location (vec[n] = n'th smallest number)
    */
    for ( int i: vec )
        std::cout << i << ", ";
    std::cout << '\n';

    std::nth_element( vec.begin(), vec.begin() + 0, vec.end() );
    std::cout << "min : " << vec[0] << '\n';

    std::nth_element( vec.begin(), vec.begin() + 0, vec.end(), std::greater{} );
    std::cout << "max : " << vec[0] << '\n';

    std::nth_element( vec.begin(), vec.begin() + vec.size()/2, vec.end() );
    std::cout << "Mediana : " << vec[vec.size()/2] << '\n';
    


    std::sort( vec.begin(), vec.end() );
    std::cout << "Sorted:\n";
    for ( int i: vec )
        std::cout << i << ", ";
    std::cout << '\n';

    return 0;
}
