#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <atomic>


static std::atomic<int> shared_value_ = 0;



void shared_value_increment_()
{
    // shared_value_ = shared_value_ + 1; // <-- this bring back the thread race problem
        // where threads can copy same value of shared_value_ multiple time instead of incrementing it
    ++shared_value_;    // atomic has overrided operators: ++, --, +=, -=, &=, |=, ^=;
}

int main()
{

    std::vector<std::thread> threads;

    for (int i = 0; i < 1000; ++i)
    {
        threads.emplace_back(std::thread(shared_value_increment_));
    }

   std::for_each(threads.begin(), threads.end(), [] (std::thread & t) { t.join(); });

   std::cout << shared_value_ << '\n';

}