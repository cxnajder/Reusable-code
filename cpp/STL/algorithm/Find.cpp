#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::vector<int> vec = {1,2,3,4};

//    std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 4 );
    auto it = std::find(vec.begin(), vec.end(), 4 );
    if(it == vec.end())
        std::cout << "Not found.\n";
    else
        std::cout << "Found " << *it << " at " << &(*it) << ".\n";
    return 0;
}
