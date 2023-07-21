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
        std::cout << "jThread id: "<< std::this_thread::get_id() << '\n';
        std::cout << "====================\n";
    };

    std::vector<std::jthread> jthreads;

    for (int i = 0; i < 5; ++i)
    {
        jthreads.emplace_back(std::jthread(lambda, i+1));
    }

}