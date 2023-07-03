/*

STL - Standard Template Libraty

    STL
    1)  containers - container adapters
    2)  interators - objects that can move/scan through container/colection
    3)  algorithms - prepered procedures to perform operations on container or its fragment

PL:

    STL:

    1) kontenery - adaptery kontenerów
        Dzielimy na:
        + sekwencyjne:  
            - vektor, 
            - deque, 
            - list
        + asociacyjne:  
            - set, 
            - map
        + nieuporządkowane (unordered):
            - unordered-set
            - unordered-map
    2) iteratory - objekty, które mogą się porószać po kontenerze
    3) algorytmy - przygotowane procedury do modyfikowania kontenerów lub ich fragmentow




*/

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack> // First In Last Out
#include <queue> // First In First Out

#include<iostream>
#include <string>

void title(std::string Title = "", std::string line_sep = "---------------------"){
    std::cout<<line_sep<<'\n';
    if (Title == "")
        return;
    std::cout<<Title<<'\n';
}

void printArrayElements(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout <<'\n';
}

int main(int argc, char const *argv[])
{
    //----------------------------------
    title("Arrey");

    std::array<int, 5> arr = {1, 2, 3}; // 4th and 5th emenet skipped on purpose

    std::cout << "arrey size    : " << arr.size() <<'\n';
    std::cout << "arrey max_size: " << arr.max_size() <<'\n';

    std::cout << "elements: ";
    printArrayElements(arr.data(), arr.size());

    //----------------------------------
    title("Vector");

    std::vector<int> vec;


    std::cout << "vector max_size: " << vec.max_size() <<'\n';
    
    std::cout << "size:" << '\t' << "capacity:" << '\n';
    std::cout << "----"  << '\t' << "---------" << '\n'; 

    std::cout << vec.size() << '\t' << vec.capacity() << '\n';

    for ( int i = 1; i <= 17; ++i )
    {
        static int last_cap = vec.capacity();

        vec.push_back(i);

        if ( vec.capacity() != last_cap )
        {
            last_cap = vec.capacity();
            std::cout << "--" << '\t' << "--" << '\n'; 
        }
        std::cout << vec.size() << '\t' << vec.capacity() << '\n';

    }

    std::cout << "elements: ";
    printArrayElements( vec.data(), vec.size());

    // vector capasity will rase every time its topped
    // starting at 0 and growing accordingly to: 1, 2, 4, 8, 16, 32 .. (multiply by two)



    /*
        VECTOR VS ARREY 

        1) vector allows us to dynamically alocate and free memory - arrey has const size.
        2) but also vector elements in sequece in memory 
        (so vector's first's element address can be used as a pointer to arrey)
    */

    //----------------------------------
    title("Deque");

    /*
        VECTOR VS DEQUE 

        + vector - cheap memory increase at the end of a vector.
        + deque  - cheap memory increase at the end and front of a deque. <-- god for snake
        + BUT in deque element are not stored in sequence in memory!
    */

    std::deque<int> deq;  // d = {}

    deq.push_back(1);     // d = {1}
    deq.push_back(2);     // d = {1, 2}

    deq.push_front(3);    // d = {3, 1, 2}
    deq.push_front(4);    // d = {4, 3, 1, 2}

    std::cout << "elements: ";
    // becouse deque elements are not is sequence i can not use the arrey iteration function
    for (auto i : deq)          
        std::cout << i << ' ';
    
    std::cout << "\n\n";

    std::cout << "deque     size() : " << deq.size() <<'\n';
    std::cout << "deque max_size() : " << deq.max_size() <<'\n';

    std::cout<<'\n';

    deq.pop_back();       // d = {4, 3, 1}
    deq.pop_front();      // d = {3, 1}

    std::cout << "deleted first and last element\n\n";

    std::cout << "elements: ";
    for (auto i : deq)
        std::cout << i << ' ';

    std::cout << '\n';

    //----------------------------------
    title("List");
    // In list every element apart from holding some data, contains adrress of next and previous element.
    // Takes up more memory BUT becouse of this, it's much easier to delete inside elements or insert element inside list!
    // (after deleteing inside element, neighbour elements will start pointing at each other)

    std::list<int> lst = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};

    std::cout << "list size    : " << lst.size() <<'\n';
    std::cout << "list max_size: " << lst.max_size() <<'\n';
    std::cout << '\n';


    std::cout << "elements: ";   

    for (std::list<int>::iterator it = lst.begin(); it != lst.end();)
    {   //                       "it" is a address of an element
        std::cout << (*it) <<' '; // printing elements

        if (*it % 2 == 0)       // if de-reference of it (value of it element) is divisible by 2 it will be erased
            it = lst.erase(it);   // erase(it) returns new adres to it (since the old address has been removed from list)
        else
            ++it;
    }
    std::cout << '\n';


    std::cout << "deleted  every even number!\n";
    
    
    std::cout << "elements: ";
    for (auto i: lst){
        std::cout << i <<' ';
    }
    std::cout << '\n';


    //----------------------------------
    title("Set");

    std::set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(2); // there will be no duplicates
    st.insert(1); // same here
    st.insert(3);

    std::cout << "inserted: 1, 2, 2, 1, 3\n";

    std::cout << "elements: ";
    for (auto i : st) {
        std::cout << i << ' ';
    } 
    std::cout << '\n';


    return 0;
}


