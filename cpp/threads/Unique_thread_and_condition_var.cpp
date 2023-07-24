#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <algorithm>


int main ( void )
{
    std::mutex mutex_lock;
    std::condition_variable condition_var;

    bool start_race = false;

    std::vector<std::thread> thread_group;

    for(int i = 0; i < 10; ++i)
    {
        thread_group.emplace_back(std::thread([&]{
            std::unique_lock<std::mutex> uniq_lock(mutex_lock);
            if(!start_race)
            {
                condition_var.wait(uniq_lock);
            }
            std::cout << "start\n";
            std::cout << "thread id: " << std::this_thread::get_id() << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "stop\n";
        }));
    }

    std::thread train_starter([&]{
        std::unique_lock<std::mutex> uniq_lock(mutex_lock);
        
        std::cout << "thread id: " << std::this_thread::get_id() << '\n';

        for(int i = 3; i > 0; --i)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << i << '\n';
        }
        std::cout << "go\n";
        start_race = true;
        condition_var.notify_all();
    });

    train_starter.join();
    std::for_each(thread_group.begin(), thread_group.end(), [] (std::thread & t) { t.join(); });

    return 0;

}
