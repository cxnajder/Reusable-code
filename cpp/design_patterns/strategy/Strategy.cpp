#include <iostream>
#include <memory>
#include <string>
#include <random>
#include <ctime>


class Strategy
{
public:
    virtual void someAlgorithm() = 0;
};

class ConcreteStrat_1 
    : public Strategy
{
public:
    void someAlgorithm() override
    {
        std::cout << "Executing Strategy 1\n";
    }
};

class ConcreteStrat_2
    : public Strategy
{
public:
    void someAlgorithm() override
    {
        std::cout << "Executing Strategy 2\n";
    }
};


bool randomBool()
{
    std::srand(std::time(NULL));
    return std::rand() % 2;
}


void strategyLoop()
{
    Strategy* strat_ptr;

    std::string input;
    std::cout << "Type 'q' or 'Q' To Quit.\n";

    while (true)
    {
        if (randomBool())
            strat_ptr = new ConcreteStrat_1;
        else
            strat_ptr = new ConcreteStrat_2;

        strat_ptr->someAlgorithm();
        delete strat_ptr;

        std::getline(std::cin, input);

        if (input == "q" || input == "Q")
            break;
    }
}

int main( void )
{
    strategyLoop();
    return 0;
}