#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

/*
 * it is a sequential container, internally implemented as doubly link list.
 * each element is stored in separate memory block. 
 *
 * push_back(), push_front(), insert()
 *
 * complexity of element insertion is O(1) if postion is already known
 * complexity of searching is O(n)
 */
 
int main()
{
    list<int> mylist;
    
    mylist.push_back(10);
    mylist.push_back(20);
    
    mylist.push_front(30);
    mylist.push_front(40);
    
    mylist.insert(mylist.begin(),50);
    
    for (int i:mylist){
        cout << i << " " ;
    }
    cout << endl;
    
    for_each (mylist.begin(), mylist.end(), [](int i){cout << i << " ";});
    
    
    return 0;
}
