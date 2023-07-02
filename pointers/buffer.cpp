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


int main(int argc, char const *argv[])
{
    Buffer b1(100);
    Buffer b2(150);
    return 0;
}
