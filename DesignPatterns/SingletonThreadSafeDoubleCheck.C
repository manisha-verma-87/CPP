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
          if (instance == NULL){
            m.lock();   // Each thread will go in ocking and unlocking the mutex which is an overhead. Hence above check is applied
            if (instance == NULL){
                instance = new Singleton();
                count++;
            }
            m.unlock();
          }
            
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
