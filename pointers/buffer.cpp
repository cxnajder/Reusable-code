#include <iostream>


class Buffer{
    int * data;
    int size;
public:
    explicit Buffer(int bufferSize);
    Buffer(const Buffer & origin);  //        COPY CONSTRUCTOR
    Buffer(Buffer && origin); // MOVING COPY CONSTRUCTOR
    ~Buffer();

    //Buffer & operator=(Buffer  b2); // in this case we would use Copy Constructor to create a copy of parameter
    Buffer & operator=(const Buffer & b2);
    Buffer & operator=(Buffer && b2);
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

Buffer::Buffer(Buffer && origin){
    data = origin.data;
    origin.data = nullptr;
    size = origin.size;

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

Buffer & Buffer::operator=(Buffer && b2){
    std::swap(data, b2.data);
    size = b2.size;

    return *this;
}

void buffer_test(Buffer b){
    return;
}

Buffer RVO_test(){
    Buffer tmp(5);
    return tmp;
}
// RVO - Return Value Optimalization

Buffer RVO_test2(){
    Buffer tmp1(2);
    Buffer tmp2(3);
    
    if (rand() % 2)
        return tmp1;
    return tmp2;
}


void value_test(int & x) {
    std::cout << "L-value : "<<x<<'\n';
}
void value_test(int && x) { // && <- is a reference to R-value
    std::cout << "R-value : "<<x<<'\n';
}


int main(int argc, char const *argv[])
{
    Buffer b1(4);
    buffer_test(b1); // no error

    Buffer b2(2);
    Buffer b3(2);
    b2 = b1 = b3;   // no error

    Buffer b4 = RVO_test(); // RVO - Return Value Optimalization / copy elision
    // The compilator sees that return value will be used as starting value of new object
    // and avoids unnecessery copies.

    Buffer b5 =  RVO_test2(); // in this case RVO will not work


    int i = 9;

    value_test(i);      // L-value
    value_test(i+1);    // R-value
    // L-value is anything that can be passed by reference
    // R-value is anything else

    // In C++11 there have been 2 new methods added:
    // 1) Object(Object && o)             <-- moving copy constructor
    //      This is a copy constructor which knows that a original object will soon disapear.
    //      It knows that it can copy/steal values from original without copying it.
    // 2) Object & operator=(Object && o) <-- moving copy operator
    //      && <- is a reference to R-value


    return 0;
}
/*
RULE OF 3:
    If any of: destructor, copy constructor, operator= is needed in out class
    that means we actualy need all 3 of them.

RULE OF 0:
    Create classes that so you wont need destructors, copy constructors and =operators.
    Simply use vectors and unique or shared pointers.

RULE OF 5:
    If we used "rule of 3" we should as well define moving copy constructor and moving =operator 
    (with && in declaration)
*/