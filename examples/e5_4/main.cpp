// Example 5.4 : type conversions (casts)
// Created by Oleksiy Grechnyev 2017

#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

struct Base{
    virtual void print(){
        cout << "Base" << endl;
    }
};

struct Derived : public Base{
    void print() override {
        cout << "Derived" << endl;
    }
};


//==============================
int main(){
    {
        cout << "\nImplicit conversions:  \n\n";
        // Primitive
        float a = 777;   // Possible loss of accuracy
        int b = 3.5;    // Loss of accuracy
        char c = 1987; // Loss of higher bytes, can be Warning

        // Non-explicit constructor  : const char[8] to string
        string s = "Phoenix";

        // cast operator , ostream to bool
        bool d(cout);  // Cannot use = here as the operator is explicit!

        cout << "a = " << a << ", b = " << b << " , s = " << s << ", d = " << d << endl;

        // Any pointer to void*
        void * vP = &b;

        // Pointer and reference upcasting (Derived* to Base* , Derived & to Base &)
        Derived derived;
        Base & baseR = derived;
        Base * baseP = &derived;
        baseR.print();   // Prints 'Derived' twice, polymorphism works
        baseP->print();
    }

    {
        cout << "\nconst_cast  \n\n";

        int a = 17;
        const int & crA = a;
        int & rA = const_cast<int &>(crA);   // Remove const
        rA = 20;
        cout << "a = " << a << endl;           // Prints 20

        double b = 1.1;
        const double * cpB = &b;
        double * pB = const_cast<double *>(cpB);   // Remove const
        *pB = 2.2;
        cout << "b = " << b << endl;          // Prints 2.2
    }

    {
        cout << "\nstatic_cast  \n\n";

    }

    return 0;
}
