#include <iostream>
#include <thread>
#include <functional>
#include <stack>
#include <chrono>
#include <mutex>
#include <cmath>

int getThreadIdAsInt() {
    // Get the ID of the current thread
    std::thread::id threadId = std::this_thread::get_id();

    // Use std::hash to convert the thread ID to a hash value (size_t)
    std::hash<std::thread::id> hashFn;
    size_t hashValue = hashFn(threadId);

    // Convert the hash value to int
    int threadIdAsInt = static_cast<int>(hashValue);

    return threadIdAsInt;
}



int main()
{

    std::stack<int> intStack;
    std::mutex mutlock;


    auto genValToStack = [&intStack, &mutlock]() {
        while (true)
        {
            if (mutlock.try_lock()) {
                intStack.push( std::abs( getThreadIdAsInt() % 10 ) );
                std::cout << '\t' << intStack.top() << "\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
                mutlock.unlock();
                std::this_thread::sleep_for(std::chrono::milliseconds(600));
            }
            else {
                std::this_thread::sleep_for(std::chrono::milliseconds(250));
            }

        }
    };

    auto PrintAndPopStack = [&intStack, &mutlock]() {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            mutlock.lock();
            std::cout << "END OF GENERATING STACK:\n\n";
            std::cout << "PRINTING STACK:\n";
            while (!intStack.empty())
            {
                std::cout << '\t' << intStack.top() << '\n';
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                intStack.pop();
            }
            std::cout << "END OF PRINTING STACK:\n\n";
            std::cout << "GENERATING STACK:\n";
            mutlock.unlock();
        }
    };



    std::cout << "GENERATING STACK:\n";

    std::thread genThread1(genValToStack);
    std::thread genThread2(genValToStack);
    std::thread genThread3(genValToStack);

    std::thread printThread(PrintAndPopStack);

    genThread1.join();
    genThread2.join();
    genThread3.join();
    printThread.join();

}