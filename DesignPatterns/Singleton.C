#include <iostream>
using namespace std;

class Singleton
{
    private:
        Singleton(){}
        int x;

    public:
        static Singleton& getInstance()
        {
            static Singleton instance;
            return instance;
        }

        Singleton(const Singleton &instance) = delete;
        Singleton operator = (const Singleton &instance)  = delete;

        void set_x(int y) 
        {
            x=y;
        }
        void print_x()
        {  
           cout << x << endl;
        }
};

int main()
{
    Singleton::getInstance().set_x(8);
    Singleton::getInstance().print_x();

    return 0;    
}


