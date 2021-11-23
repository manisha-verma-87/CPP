#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex m;

class Singleton
{
    private:
        Singleton(){}
        static Singleton* instance;
        static int count;
        
    public:
        static Singleton* getInstance()
        {
            m.lock();   // If we do not lock this critical section, two instances can get created, we can check by printing the count
            if (instance == NULL){
                instance = new Singleton();
                count++;
            }
            m.unlock();
            
            return instance;
        }

        Singleton(const Singleton &instance) = delete;
        Singleton operator = (const Singleton &instance)  = delete;
        
        void printClassDescription(int i) const {
            cout << "I am a singleton class " << i << " count = " << count << endl;
        }
};

Singleton* Singleton::instance = NULL;
int Singleton::count = 0;

void print(int i){
  while (true){
    Singleton::getInstance()->printClassDescription(i);
  }
}

int main()
{
    thread th1(print, 1);
    thread th2(print, 2);
    
    th1.join();
    th2.join();
    return 0;    
}
