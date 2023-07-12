#include <vector>
#include <iostream>
#include <algorithm>

void sortedHowIntVec ( std::vector<int>::iterator begin, std::vector<int>::iterator end, bool ascending = true)
{

    static std::vector<int>::iterator begin_ = begin;

    auto it = begin;

    if ( ascending ) 
        it = std::is_sorted_until( begin, end );
    else
        it = std::is_sorted_until( begin, end, std::greater{} );


    if ( std::distance( begin, it ) <= 1 && distance( begin, end ) != 1 )
        sortedHowIntVec( begin, end, !ascending);
    else
    {
        std::cout << "Sorted ";
        if ( ascending ) 
            std::cout << "ascending ";
        else
            std::cout << "descending ";
        
        std::cout << "from ";
        std::cout << std::distance( begin_, begin );
        std::cout << " to ";
        std::cout << std::distance( begin_, it ) << '\n';

        if ( it == end )
            return;

        sortedHowIntVec( it, end, !ascending );

    }

}

int main()
{

    std::vector<int> vec = { 1, 2, 3, 4, 3, 2, 1, 2, 3, 2, 1, 2, 3, 4, 5, 6, 5 };

    sortedHowIntVec( vec.begin(), vec.end() );

    /*

    // SIMPLE EXAMPLE

    std::vector<int> vec = { 5, 4, 3, 2, 6, 7, 8 };

    for (auto n { vec.size() }; int i : vec )
        std::cout << i << ( --n ? ", " : "" );
    std::cout << '\n';


    auto it =  std::is_sorted_until( vec.begin(), vec.end() );

    std::cout << "Sorted ascending  from ";
    std::cout << std::distance( vec.begin(), vec.begin() );
    std::cout << " to ";
    std::cout << std::distance( vec.begin(), it ) << '\n';



    it = std::is_sorted_until( vec.begin(), vec.end(), std::greater{} );

    std::cout << "Sorted descending from ";
    std::cout << std::distance( vec.begin(), vec.begin() );
    std::cout << " to ";
    std::cout << std::distance( vec.begin(), it ) << '\n';

    

    auto it2 = std::is_sorted_until( it, vec.end() );

    std::cout << "Sorted ascending  from ";
    std::cout << std::distance( vec.begin(), it );
    std::cout << " to ";
    std::cout << std::distance( vec.begin(), it2 ) << '\n';
    */


    return 0;
}
