#include <iostream>
#include <vector>
using namespace std;

class Singleton
{
    private:
        Singleton(){}
        static Singleton* instance;
        
    public:
        static Singleton* getInstance()
        {
            if (instance == NULL){
                instance = new Singleton();
            }
            
            return instance;
        }

        Singleton(const Singleton &instance) = delete;
        Singleton operator = (const Singleton &instance)  = delete;
        
        void printClassDesription() const {
            cout << "I am a singleton class" << endl;
        }
};

Singleton* Singleton::instance = NULL;

int main()
{
    Singleton::getInstance()->printClassDesription();
    
    return 0;    
}

