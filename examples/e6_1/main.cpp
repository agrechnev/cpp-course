// Example 6.1 : scope, memory management unique_ptr
// Created by Oleksiy Grechnyev 2017

#include <iostream>
#include <iomanip>
#include <string>

#include "Tjej.h"

using namespace std;

// Global variable
Tjej glob("Globula Statika");


//==============================
// Factory (soure) function example
unique_ptr<Tjej> factory(const string & name){
    return make_unique<Tjej>(name); // No need for explicit move here
}
//==============================
// Sink (consumer) example which destroys a unique_ptr<Tjej> object
// Note the rvalue ref unique_ptr<Tjej> && pT
void sink(unique_ptr<Tjej> && pT){
    unique_ptr<Tjej> pT2 = move(pT); // We can do that
    cout << "Sink: name = " << pT2->getName() << endl;
    // Now the object is destroyed as it goes out of scope !
}
//==============================
int main(){
    {
        cout << "\nLocal and temp objects :  \n\n";
        Tjej *pT = new Tjej("Heap Tjej");
        Tjej t1("Local Tjej");
        Tjej("Temp Tjej");
        delete pT;
    }

    {
        cout << "\nunique_ptr example 1:  \n\n";
        unique_ptr<Tjej> pT1 = make_unique<Tjej>("Maria");  // Create a new heap object owned by a unique PTR
        unique_ptr<Tjej> pT2(new Tjej("Anna")); // This is also OK

        cout << "name1 = " << pT1->getName() << endl;  // You can access members like this
        cout << "name2 = " << (*pT2).getName() << endl;  // Or like this
        unique_ptr<Tjej> pT3 = move(pT1); // Move is OK, copy is not
    }

    {
        cout << "\nunique_ptr example 2: Source (factory) and sink (consumer).  \n\n";
        unique_ptr<Tjej> pT = factory("Souce of all magic");  // Create a new heap object owned by a unique PTR
        cout << "name = " << pT->getName() << endl;
        // No we move pT to sink(), where it is destroyed
        sink(move(pT));
        cout << "After sink" << endl;
    }

    return 0;
}
