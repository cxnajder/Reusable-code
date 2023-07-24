#include <iostream>
#include <future>
#include <chrono>
#include <string>
#include <thread>

std::string waitAndReturnStr(const std::string & txt)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return txt;
}

int main( void )
{
    std::future<std::string> asyncFun = std::async(&waitAndReturnStr, "FUTURE");

    std::cout << "Welcome ";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "To ";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "The ";

    std::string msg = asyncFun.get();
    std::cout << msg;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << '\n';
    

    return 0;
}
