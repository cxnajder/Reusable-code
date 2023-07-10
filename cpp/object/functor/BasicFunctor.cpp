#include <iostream>

class ValueHolder
{
    int val{0};
public:
    int operator()(int newVal)
    {
        val = newVal;
        return val;
    }
        int operator()()
    {
        return val;
    }
};

int main()
{
    ValueHolder vh1;
    int vh1_val_copy = vh1(99999);
    std::cout <<  vh1() << "\t" << vh1_val_copy << '\n';
    return 0;
}
