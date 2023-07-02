#include <iostream>


class Buffer{
    int * data;
    int size;
public:
    explicit Buffer(int bufferSize);
    Buffer(const Buffer & origin);  // COPY CONSTRUCTOR
    ~Buffer();
};

Buffer::Buffer(int bufferSize){

    if (bufferSize < 1)
        throw std::runtime_error("Invalid buffer size.");

    data = new int[bufferSize];
    size = bufferSize;

    // MALLOC vs NEW difference:

    // malloc does not call object constructors!
    // with new type[x] x is the number of elements
    // malloc requireS to specify number of bytes
}

Buffer::Buffer(const Buffer & origin){ // COPY CONSTRUCTOR
    // REQUIRED TO PREVENT THE SAME MEMORY FROM BEAING RELEASED MULTIPLE TIMES!!!
    data = new int[origin.size];
    size = origin.size;
    std::copy(origin.data, origin.data + origin.size, data);
}

Buffer::~Buffer() {
    delete [] data; 
    // REQUIRED TO FREE MEMORY IN DESTRUCTOR TO PREVENT MEMORY LEAK!!!
}

void buffer_test(Buffer b){
    return;
}

int main(int argc, char const *argv[])
{
    Buffer b1(4);
    buffer_test(b1); // no error

    Buffer b2(2);
    b2 = b1; // STILL THE SAME ERROR: free(): double free detected in tcache 2
    // NOW BOTH b1 AND b2 AREPOINTING AT THE SAME MEMORY.
    // NOT ONLY DESCTRUCTORS ATTEMP TO RELEASE THE SAME MEMORY TWICE 
    // BUT ALSO WE HAVE A MEMORY LEAK OF THE MEMORY FIRST ASSIGNEG DO b2.

    // to solve tis we need to define new = (copy) operator
    return 0;
}
