#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    int i = 10;
    int& j = i; // lvalue reference (prior to C++11, we had only references. Now we call it as lvalue reference)
    //int&& k = i; //  error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int'
    int&& k = move(i); // move retrieves rvlaue from 'i'
    
    cout << i << ", " << j << ", " << k << endl;
    return 0;
}
