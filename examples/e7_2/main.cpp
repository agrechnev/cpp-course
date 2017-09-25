// Example 7.2 : std::vector
// Created by Oleksiy Grechnyev 2017
// Class Tjej is used here, it logs Ctors and Dtors

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

#include "Tjej.h"

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
//==============================
/// Print a container. This version uses iterators
template <typename C>
void print2(const C & c){
    for (auto it = begin(c); it != end(c); ++it)
        cout << *it << " ";
    cout << endl;
}

//==============================
int main(){
    {
        cout << "-----------------------------";
        cout << "\nstd::vector creation :  \n\n";
        
        vector<int> vI1;            // Empty vector
        vI1.push_back(11);          // Add elements to an empty vector
        vI1.push_back(12);
        vI1.push_back(13);
        cout << "vI1 = "; print(vI1);
        
        vector<int> vI2(10);        // vector of 10 elements
        cout << "vI2 = "; print(vI2);
        
        vector<int> vI3(10, 13);    // vector of 10 elements equal to 13
        cout << "vI3 = "; print(vI3);
        
        vector<int> vI4{10, 13};    // vector of two elements : 10, 13
        cout << "vI4 = "; print(vI4);
        
        vector<int> vI5 = {2, 3, 7, 11, 13, 17, 19, 23};    // List assignment constructor
        cout << "vI5 = "; print(vI5);
        
        vector<string> vS{"Maria", "Nel", "Sophia", "Clair", "Mirage"};    // List constructor
        cout << "vS = "; print(vS);
    }

    {
        cout << "-----------------------------";
        cout << "\nstd::vector logging copy/move operations :  \n\n";
        
        {
            cout << "\ncreate 5 elements, then fill with at(): \n" << endl;
            vector<Tjej> vT1(5);   // Note: that calls default constructor of Tjej 5 times !!!
            for (int i=0; i < 5; ++i) {
                string s = "Tjej #" + to_string(i);
                vT1.at(i) = Tjej(s);
            }
        }
        
        {
            cout << "\nfill with push_back() : move : \n" << endl;
            vector<Tjej> vT1(5);   // Note: that calls default constructor of Tjej 5 times !!!
            for (int i=0; i < 5; ++i) {
                string s = "Tjej #" + to_string(i);
                vT1.at(i) = Tjej(s);
            }
        }
    }
    
    
    return 0;
}
