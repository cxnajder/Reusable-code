#include <iostream>


class Buffer{
    int * data;
    int size;
public:
    explicit Buffer(int bufferSize);
    ~Buffer();
};

Buffer::Buffer(int bufferSize): size(bufferSize){

    if (bufferSize < 1)
        throw std::runtime_error("Invalid buffer size.");

    data = new int[size];

    // MALLOC vs NEW difference:

    // malloc does not call object constructors!
    // with new type[x] x is the number of elements
    // malloc requireS to specify number of bytes
}

Buffer::~Buffer() {
    delete [] data; 
    // REQUIRED TO FREE MEMORY IN DESTRUCTOR TO PREVENT MEMORY LEAK!!!
}

void buffor_error(Buffer b){
    return;
}

int main(int argc, char const *argv[])
{
    Buffer b1(4);
    buffor_error(b1); // ERROR: free(): double free detected in tcache 2

    // b1 HAS BEEN COPIED TO buffor_error FUNCTION WITH POINTER TO THE SAME MEMORY
    // (now we have 2 buffers - one in main and one in function - BOTH POINTING TO THE SAME MEMORY!)
    // WHEN THE FUNCTION ENDED, THE OBJECT (copy of b1) WAS DESTROYED
    // THAT CALLED THE DESTRUCTOR OF THE OBJECT WITCH FREED THE MEMORY OF b1
    // b1 STILL EGZISTS BUT ITS POINTING TO THE MEMORY THAT HAS BEEN FREED!!!

    // AFTER EXITING MAIN b1 WILL TRY TO RELEASE MEMORY THAT HAS BEEN ALREADY RELEASED!

    // TO SOLVE THIS A NEW COPU CONSTRUCTOR IS REQUIRED!

    return 0;
}
