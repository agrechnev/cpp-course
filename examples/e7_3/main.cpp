// Example 7.3 : std::set, std::map
// Created by Oleksiy Grechnyev 2017

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

//=======================================
/// Print a container. Works also with built-in arrays.
/// pair from maps cannot be printed like this
template <typename C>
void print(const C & c){
    for (const auto & e : c)
        cout << e << " ";
    cout << endl;
}
//=======================================
/// Prints a map. 
template <typename C>
void printMap(const C & c){
    for (const auto & e : c)
        cout << e.first << " : " << e.second << endl;
}

//==============================
int main(){
    {
        cout << "-----------------------------";
        cout << "\nstd::set operations :  \n\n";
        
        set<int> s{1, 22, 2, 3, 19, 1, 3, 8, 12, 19, 22};  // Repeated, unsorted
        // Contains : 1 2 3 8 12 19 22
        cout << "s = "; print(s);

        cout << "s.count(22) = " << s.count(22) << endl;    // Returns 0, 1
        auto pos = s.find(22); // Returns iterator or s.end() if not found
        
        // Insert elements
        s.insert(5);
        s.emplace(7);
        s.insert({11, 13, 17, 19, 23});
        cout << "s = "; print(s);
        // 1 2 3 5 7 8 11 12 13 17 19 22

        // Delete elements
        s.erase(8);
        s.erase(12);
        s.erase(22);
        cout << "s = "; print(s);
        // 1 2 3 5 7 11 13 17 19 23
    }


    return 0;
}
