#include <iostream> // for runtime_error()

// PARAMETRIC/GENERIC CLASS
// This type of class wont be compiled until we declare somwhere in code
// that we would like to use this class for some type (like int/double/float).

// template <class T>    <-- in older version on c++
template <typename T> // <-- type chosen later by programer
class Stack {
    T * data;
    int size;
    int last;    

    Stack(const Stack &) = delete;
    Stack & operator=(const Stack &) = delete;
public:
    explicit Stack(int stackSize);
    ~Stack();

    void push(T val);
    T pop();
};

// The generic functions bellow are usally written in HEADER file!
template <typename T>
Stack<T>::Stack(int stackSize) { // Stack<T> is a "parametric" class
    data = new T[stackSize];
    size = stackSize;
    last = -1; 
}

template <typename T>
Stack<T>::~Stack() {
    delete [] data;
}

template <typename T>
void Stack<T>::push(T val){
    if (last == size-1)
        throw std::runtime_error("Trying to push() to full stack.");

    data[++last] = val;
}

template <typename T>
T Stack<T>::pop(){
    if (last <= -1)
        throw std::runtime_error("Trying to pop() from empty stack.");

    return data[last--];
}


int main(int argc, char const *argv[])
{
    Stack<double> d_stk(7);     // <- this looks similar to vector<T>

    for (int i = 1; i < 8; ++i)
        d_stk.push(i + .11*i);
    
    for (int i = 0; i < 7; ++i)
        std::cout<<d_stk.pop()<<'\n';

    return 0;
}

