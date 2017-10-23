// Example 13.1 Template : variadic, metaprogramming
// Created by Oleksiy Grechnyev 2017
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//==============================
// Template functions
//==============================
// Variadic

// Size of the variadic pack
template <typename... Args>
size_t packSize(const Args & ... pack){
    return sizeof...(pack);
//    return sizeof...(Args);  // Same result
}

// print: print all args to stdout
// Non-variadic print (to break the recursion)
template <typename T>
void print(const T & t){
    cout << t << endl;
}
// The variadic overload
template <typename T, typename... Args>
void print(const T & t, const Args & ... rest){
    cout << t << endl;
    print(rest...);
}

// print2: print all args to stdout using expansion (UGLY)
template <typename... Args>
void print2(const Args & ... args){
    int temp[] = {(print(args), 0)...};
}

// printSq: print numerical args to stdout, squared
template <typename T>
T square(const T & t){
    return t*t;
}
template <typename... Args>
void printSq(const Args & ... args){
    print(square(args)...);
}

//==============================
// main() 
//==============================
int main() {
    {
        cout << "\nVariadic templates : \n\n";
        cout << boolalpha;

        cout << "packsize = " << packSize(13, "Carrot", 91, 'A', true, 'Z', 3.14159) << endl;

        cout << "\nprint() :\n";
        print(13, "Carrot", 91, 'A', true, 'Z', 3.14159);

        cout << "\nprint2() :\n";
        print2(13, "Carrot", 91, 'A', true, 'Z', 3.14159);

        cout << "\nprintSq() :\n";
        printSq(1, 2, 3.14159);
    }
    return 0;
}
