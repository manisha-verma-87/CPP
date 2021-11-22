#include<iostream>
#include<unordered_map>
using namespace std;

/**
 * unordered_map internally used hash table to store elements
 * 
 * unordered_map uses more memory as compared to map as it aslo sores the hash table
 *
 * The complexity of searching an element in undered_map is O(1) in best case,
 * and O(n) in worst case.
 * Worst case is the result if bad hash function.
 * If the hash function is not good and results into collisions then the complexity for searching the element can be O(n).
 *
 * Where in map, the complexity for searching an element is guaranteed to be O(log n).
 * 
 * Important functions
 * same as of map
 */
