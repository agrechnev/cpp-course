// Example 4.1 : Class Ctors, Dtors, copy/move ctors and assignments using class Tjej
// Created by Oleksiy Grechnyev 2017
#include <iostream>

#include "Tjej.h"

int main(){
    using namespace std;
    // The blocks here limit the scope, so that destructors kick in at the end of each block
    // Everything is destroyed by the end of each block
    {
        cout << "Initialization :" << endl;
        Tjej t1; //Default ctor: Lilith
        
        // These 5 forms of initialization are more or less equivalent (unless use std::initializer_list)
        Tjej t2("Kajsa");
        Tjej t3 = Tjej("Anna");  // No copy/move here ! And no assignment !
        Tjej t4{"Maria"};
        Tjej t5 = {"Eva"}; // Again, no assignment ! This is impossible with explicit ctor.
        Tjej t6 = string("Hedvig"); // Again, not possible with explicit ctor
        
        // Note: destructors work in the reverse order for local vars
    }
    
    
    return 0;
}
