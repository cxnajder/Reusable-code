#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = { 8, 4, 2, 1, 9, 7, 6, 3, 5, };
    /*
        nth_element(vec.begin(), vec.begin() + n, vec.end());

        Where n is the n-th number we are looking for (n'th smallest number)
        and it will be assigned at n location (vec[n] = n'th smallest number).

        It will move  all the smaller values then n to the left, 
        and greater values to the right

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
    
    for ( int i: vec )
        std::cout << i << ", ";
    std::cout << '\n';


    for (int i = 0; i < vec.size()/2; ++i)
        std::cout << "-  ";
    std::cout << "^  ";
    for (int i = 0; i < vec.size() - vec.size()/2 - 1; ++i)
        std::cout << "+  ";
    std::cout << '\n';
    // Printing underline of medinana 
    // '^' <-- points at mediana 
    // '-' <-- smaler then mediana
    // '+' <-- larger then mediana
    

    std::sort( vec.begin(), vec.end() );
    std::cout << "Sorted:\n";
    for ( int i: vec )
        std::cout << i << ", ";
    std::cout << '\n';

    return 0;
}
