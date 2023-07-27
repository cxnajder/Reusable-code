#include <iostream>
#include <thread>
#include <functional>
#include <stack>
#include <chrono>
#include <mutex>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>

const int _MS_GEN_STEP = 100;
const int _MS_PRINT_POP_STEP = 500;
const int _MS_MAIN_LOOP_SLEEP = 1000;
const int _NUM_OF_THREADS = 3;



int main()
{

    std::stack<int> intStack;
    std::mutex mutlock;

    std::vector<std::thread> thread_group;


    auto genValToStack = [&intStack, &mutlock]() {
        while (true)
        {
            if (mutlock.try_lock()) {
                std::stringstream ss;
                ss << std::this_thread::get_id();
                intStack.push( std::stoi( ss.str() ) );
                std::cout << '\t' << intStack.top() << "\n";
                mutlock.unlock();
                std::this_thread::sleep_for(std::chrono::milliseconds(_MS_GEN_STEP * _NUM_OF_THREADS));
            }
            else {
                std::this_thread::sleep_for(std::chrono::milliseconds(_MS_GEN_STEP));
            }

        }
    };

    auto PrintAndPopStack = [&intStack, &mutlock]() {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(_MS_MAIN_LOOP_SLEEP));
            mutlock.lock();
            std::cout << "END OF GENERATING STACK:\n\n";
            std::cout << "PRINTING STACK:\n";
            while (!intStack.empty())
            {
                std::cout << '\t' << intStack.top() << '\n';
                std::this_thread::sleep_for(std::chrono::milliseconds(_MS_PRINT_POP_STEP));
                intStack.pop();
            }
            std::cout << "END OF PRINTING STACK:\n\n";
            std::cout << "GENERATING STACK:\n";
            mutlock.unlock();
        }
    };



    std::cout << "GENERATING STACK:\n";

    for (int i = 0; i < _NUM_OF_THREADS; ++i)
    {
        thread_group.emplace_back(std::thread(genValToStack));
    }

    PrintAndPopStack();

    std::for_each(thread_group.begin(), thread_group.end(), [](std::thread& t) { t.join(); });


}
