#include <iostream>
#include <future>
#include <chrono>
#include <string>
#include <thread>
#include <vector>


void printDots(int rep)
{
    for(int i = 0; i < rep; ++i)
    {
        std::cout << '.';
        std::this_thread::sleep_for(std::chrono::milliseconds( 100 ));
    }
}

void printAndWait(const std::vector<std::string> & words)
{
    for(std::string word : words)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds( 200 ));
        for(char letter : word)
        {
            std::cout << letter;
            std::this_thread::sleep_for(std::chrono::milliseconds( 100 ));
        }
    }
}


int main( void )
{
    std::vector<std::string> message = { "Hello", "World", "my", "name", "is", "Main", "Thread", "!", "Nice", "to", "meet", "You", "!!!" };

    std::future<void> asyncFun = std::async(&printDots, 100);


    std::this_thread::sleep_for(std::chrono::milliseconds( 1000 ));
    printAndWait(message);

    return 0;
}
