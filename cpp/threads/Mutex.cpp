#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <mutex>


static int shared_value_ = 0;

std::mutex globalLock;

void shared_value_increment_()
{
    globalLock.lock();
        shared_value_ = shared_value_ + 1;
    globalLock.unlock();
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