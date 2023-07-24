#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

void raceFunction(char ch) {
    for (int i = 0; i < 10; ++i) 
        std::cout << ch;
}

int main() {

    std::vector<std::thread> threads;

    for(int i = 0; i < 24; ++i)
        threads.emplace_back(std::thread(raceFunction, 'a'+i));

    std::for_each(threads.begin(), threads.end(), [] (std::thread & t) { t.join(); });

    return 0;
}
