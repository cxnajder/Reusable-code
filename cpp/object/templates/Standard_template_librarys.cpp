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

#include <vector>
#include <array>
#include <stack> // First In Last Out
#include <queue> // First In First Out
#include <deque>
#include <list>
#include <map>
#include <set>

#include<iostream>
#include <string>

void title(std::string Title = "", std::string line_sep = "-------------------"){
    std::cout<<line_sep<<'\n';
    if (Title == "")
        return;
    std::cout<<Title<<'\n';
}

int main(int argc, char const *argv[])
{
    //----------------------------------
    title("Vector");

    std::vector<double> v;
    v.push_back(3.14);
    v.size();
    std::cout << "vector size    : "<<v.size()<<'\n';
    std::cout << "vector v[0]    : "<<v[0]<<'\n';
    std::cout << "vector v.at(0) : "<<v.at(0)<<'\n';
    v.pop_back();

    //----------------------------------
    title("Arrey");

    std::array<int, 2> a = {1, 2};

    a.size();
    a[0] = -99;
    a.at(1) = 100;

    std::cout<<"arrey size :  "<<a.size()<<'\n';
    
    for (auto i: a){
        std::cout<<i<<'\n';
    }

    //----------------------------------
    title("Set");

    std::set<char> s;
    s.insert('G');
    s.insert('F');
    s.insert('G'); // there will be no duplicates
    for (auto& str : s) {
        std::cout << str << ' ';
    } 
    std::cout << '\n';


    return 0;
}


