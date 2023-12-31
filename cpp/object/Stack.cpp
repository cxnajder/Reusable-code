#include <iostream>

class Stack {
    int * data;
    int size;
    int last;   // marks last saved space

    Stack(const Stack &) = delete; // makes sure copy constructor and =op are forbiden
    Stack & operator=(const Stack &) = delete;  // avilable since C++11
    // in older version leave declaration in private section without "= delete"
public:
    explicit Stack(int stackSize);
    ~Stack();

    void push(int val);
    int pop();
};

Stack::Stack(int stackSize) {
    data = new int[stackSize];
    size = stackSize;
    last = -1; // -1 means that stack is empty (0 stands for first index)
}

Stack::~Stack(){
    delete [] data;
}

void Stack::push(int val){
    if (last == size-1)
        throw std::runtime_error("Trying to push() to full stack.");

    data[++last] = val;
}

int Stack::pop(){
    if (last <= -1)
        throw std::runtime_error("Trying to pop() from empty stack.");

    return data[last--];
}

void reference_constr_test(Stack s){ // this function should throw error
    return;
}

 void keep_window_open()
{
	std::cin.clear();
	std::cout << "Please enter a character to exit\n";
	char ch;
	std::cin >> ch;
	return;
}

 void keep_window_open(std::string s)
{
	if (s == "") return;
	std::cin.clear();
	std::cin.ignore(120, '\n');
	for (;;) {
		std::string ss;
        do {
			std::cout << "Please enter " << s << " to exit\n";
        } while (std::cin >> ss && ss != s);
        
		return;
	}
}


int main(int argc, char const *argv[])
{   
    try{
        Stack stk(5);

        for (int i = 1; i < 6; ++i)
            stk.push(i);

        //stk.push(999);  // push error
        
        for (int i = 0; i < 5; ++i)
            std::cout<<stk.pop()<<'\n';

        //stk.pop();      // pop error

        //Stack stk2 = stk;             // wont even compile
        // "error: use of deleted function ‘Stack::Stack(const Stack&)’"

        //reference_constr_test(stk);   // wont compile aswel
        // "error: use of deleted function ‘Stack::Stack(const Stack&)’"

        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        keep_window_open("~~");
        return 1;
    }
    catch(...)
    {
        std::cerr << "Exception \n";
        keep_window_open("~~");
        return 2;
    }
}
