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

int main(int argc, char const *argv[])
{
    //----------------------------------
    title("Arrey");

    std::array<int, 5> a = {1, 2, 3}; // 4th and 5th emenet skipped on purpose

    a.size();
    a[0] = -99;
    a.at(1) = 100;

    std::cout << "arrey size    : " << a.size() <<'\n';
    std::cout << "arrey max_size: " << a.max_size() <<'\n';

    std::cout << "elements: ";
    for (auto i: a){
        std::cout << i <<", ";
    }
    std::cout << '\n';

    //----------------------------------
    title("Vector");

    std::vector<double> v;

    std::cout << "vector size    : " << v.size() <<'\n';
    v.push_back(3.14);
    std::cout << "vector size    : " << v.size() <<'\n';
    std::cout << "vector max_size: " << v.max_size() <<'\n';
    std::cout << "vector v[0]    : " << v[0] <<'\n';
    std::cout << "vector v.at(0) : " << v.at(0) <<'\n';
    v.pop_back();

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

    std::deque<int> d;  // d = {}

    d.push_back(1);     // d = {1}
    d.push_back(2);     // d = {1, 2}

    d.push_front(3);    // d = {3, 1, 2}
    d.push_front(4);    // d = {4, 3, 1, 2}

    std::cout << "elements: ";
    for (auto i : d) {
        std::cout << i << ", ";
    }
    std::cout << "\n\n";

    std::cout << "deque     size() : " << d.size() <<'\n';
    std::cout << "deque max_size() : " << d.max_size() <<'\n';

    std::cout<<'\n';

    d.pop_back();       // d = {4, 3, 1}
    d.pop_front();      // d = {3, 1}

    std::cout << "elements: ";
    for (auto i : d) {
        std::cout << i << ", ";
    }
    std::cout << '\n';

    //----------------------------------
    title("List");
    // In list every element apart from holding some data, contains adrress of next and previous element.
    // Takes up more memory BUT becouse of this, it's much easier to delete inside elements or insert element inside list!
    // (after deleteing inside element, neighbour elements will start pointing at each other)

    std::list<int> l = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};

    std::cout << "list size    : " << l.size() <<'\n';
    std::cout << "list max_size: " << l.max_size() <<'\n';
    std::cout << '\n';

    std::cout << "elements: ";
    for (auto i: l){
        std::cout << i <<", ";
    }
    std::cout << '\n';
    
    for (std::list<int>::iterator it = l.begin(); it != l.end();)
    {   //                       "it" is a address of an element
        if (*it % 2 == 0)       // if de-reference of it (value of it element) is divisible by 2 it will be erased
            it = l.erase(it);   // erase(it) returns new adres to it (since the old address has been removed from list)
        else
            ++it;
    }
    std::cout << "deleted  every even number!\n";
    
    
    std::cout << "elements: ";
    for (auto i: l){
        std::cout << i <<", ";
    }
    std::cout << '\n';


    //----------------------------------
    title("Set");

    std::set<char> s;
    s.insert('G');
    s.insert('F');
    s.insert('G'); // there will be no duplicates

    std::cout << "elements: ";
    for (auto& str : s) {
        std::cout << str << ", ";
    } 
    std::cout << '\n';


    return 0;
}


