#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <mutex>


static int shared_value_ = 0;

std::mutex globalLock;

void shared_value_increment_()
{
    std::lock_guard<std::mutex> lockGuard(globalLock);
    // Lock gurad makes sure that even an exception is thrown
    // the destructor for the lock gurad will release all mutexes
    try {
        shared_value_ = shared_value_ + 1;
        throw std::runtime_error("test");
    }
    catch(std::runtime_error e){
        return;
    }
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