#include<iostream>
#include<map>
using namespace std;


//
// Map is internally inplemented as a self-balancing red-black tree.
//
// AVL tree and Red black tree are most common self-balancing binary search tree.
// 
// insert/delete operations oin both trees are O(log n) complexity.
// In the case of Red-Black tree re-balancing rotation is an O(1) operation 
// while with AVL this is a O(log n) operation
//
// Since re-balancing of Red-black tree is O(1), it is preferred over AVL tree.
// 
// complexity of searching an element is O(log(n))
//
//
// imp functions
// begin()
// end()
// size()
// max_size()
//
//

int main()
{
   map<string, int> directory;

   directory["Manisha"] = 89765;

   // insert using make_pair
   directory.insert(make_pair("Ritesh", 9876));

   // insert using pair
   directory.insert(pair<string, int>("Ishita", 86452));

   // insert using insert
   directory.insert({"Rawat", 86452});

   // using range based for loop (C++11 feature)
   cout << "\nTraverse using range based loop\n";
   for (auto& kv : directory)
   {
       cout << kv.first << " " << kv.second << endl;
   }

   // using iterators
   cout << "\nTraverse using iterators\n";
   map<string, int>::iterator it;

   for (it = directory.begin(); it != directory.end(); it++)
   {
       cout << it->first << " " << it->second << endl;
       it->second = 1000;
   }

   // using range based iterator using key,value (C++17)
   cout << "\nTraverse using range based loop with [key, value]\n";
   for (auto [key, value] : directory)
       cout << key << " " << value << endl; 

   cout << "\nPrint size(elements it is holding) using size()\n";
   cout << directory.size() << endl;
   cout << "\nPrint max size (maximum elements it can hold) using size()\n";
   cout << directory.max_size() << endl;
   return 0;
}
