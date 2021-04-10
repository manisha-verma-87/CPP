#include<iostream>
#include<map>
using namespace std;


//
// Map is internally inplemented as a balanced binary search tree (AVL/Red black tree)
//
// complexity of searching an element is O(log(n))
//
//

int main()
{
   map<string, int> directory;

   directory["Manisha"] = 89765;
   directory.insert(make_pair("test", 9876));

   for (auto& kv : directory)
   {
       cout << kv.first << " " << kv.second << endl;
   }

   return 0;
}
