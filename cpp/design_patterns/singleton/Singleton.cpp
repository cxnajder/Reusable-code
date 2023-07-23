
class Singleton
{
private:
    Singleton();
    static Singleton * singleton_ptr;

public:

    Singleton(const Singleton &) = delete;
    Singleton & operator=(const Singleton &) = delete;

    static Singleton * GetInstance();
    
};

Singleton::Singleton(){}
Singleton * Singleton::singleton_ptr = nullptr;
Singleton * Singleton::GetInstance()
{
    if(singleton_ptr == nullptr)
        singleton_ptr = new Singleton();
    return singleton_ptr;
}



int main()
{
    Singleton * signl_ = Singleton::GetInstance();
    return 0;
}
