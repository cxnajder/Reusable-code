#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>


void testSome(int x)
{
    std::cout << "Hi from function " << x << '\n';
}

int main()
{
    auto lambda = [](int n) 
    {
        std::cout << "Hello from lambda: " << n << '\n';
        std::cout << "Thread id: "<< std::this_thread::get_id() << '\n';
        std::cout << "====================\n";
    };

    std::vector<std::thread> threads;

    for (int i = 0; i < 5; ++i)
    {
        threads.emplace_back(std::thread(lambda, i+1));
    }

    std::for_each(threads.begin(), threads.end(), [] (std::thread & t) { t.join(); });

}