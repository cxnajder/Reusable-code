#include <string>
#include <iostream>

class OpenFile
{
public:
    OpenFile(const std::string & filename) { std::cout << "Opening file " << filename << '\n'; }
    void closeFile() { delete this; }
private:
    ~OpenFile() { std::cout << "File is being closed\n"; } // private destructor 
    // that means object can be destrojed by itself, other object with same type or its friends.

    // makeing sure copy-constructor and assign-operator wont be used:
    OpenFile( OpenFile & ) = delete;
    OpenFile & operator = ( OpenFile & ) = delete;
};

int main(void)
{
    /*
    OpenFile f("data.txt");
    f.closeFile();

    // This code wont compile becose object f is stored on stack 
    // and event thought f has been destrojed with .closeFile() method
    // after closeing main, program would try to delete f from stack
    // (it would try to call destructor for the f again -- private destructor error) 
    // (("error: ‘OpenFile::~OpenFile()’ is private within this context"))

    */

    OpenFile * f = new OpenFile("data.txt");
    f->closeFile();

    // This code will compile and work
    // becouse f is now stored on heap
    // 
    return 0;
}
