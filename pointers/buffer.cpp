#include <iostream>


class Buffer{
    int * data;
    int size;
public:
    explicit Buffer(int bufferSize);
    Buffer(const Buffer & origin);  // COPY CONSTRUCTOR
    ~Buffer();
    Buffer & operator=(const Buffer & b2);
    //Buffer & operator=(Buffer  b2); // in this case we would use Copy Constructor to create a copy of parameter
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

/*

Buffer & Buffer::operator=(Buffer b2){
    int * tmp = data;
    data = b2.data;
    b2.data = tmp;  // we are swapping datat with temporary-created local object b2 (with copy constructor)
    // (becouse it's temporary the temp data will be deleted with destructor right after closeing this function)

    size = b2.size;

    return *this;
}
*/

/*

Buffer & Buffer::operator=(const Buffer & b2){
    delete [] data;
    data = new int[b2.size];
    size = b2.size;
    std::copy(b2.data, b2.data + b2.size, data);

    return *this;
}
// Problems:
// 1) b1 = b1 ?
// 2) if new fails (not enought memory) the destructor will be callde but data has been already deleted! 
//    (error - multible delete data attemps)

*/
Buffer & Buffer::operator=(const Buffer & b2){

    if (this == &b2) // checking if ths and b2 are the same object (b1 = b1;)
        return *this;

    if (size != b2.size){
        // if sizes are diffrent we will realocate memory
        int * tmp = new int[b2.size]; // if this allocation fails data wont be deleted twice!
        delete [] data; // we delete data only after successful allocation
        data = tmp;
        size = b2.size;
    }

    std::copy(b2.data, b2.data + b2.size, data);

    return *this;
}


void buffer_test(Buffer b){
    return;
}

int main(int argc, char const *argv[])
{
    Buffer b1(4);
    buffer_test(b1); // no error

    Buffer b2(2);
    Buffer b3(2);
    b2 = b1 = b3;   // no error

    return 0;
}
