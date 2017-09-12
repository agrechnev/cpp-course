// Example 5.1 : istream, ostream 
// Created by Oleksiy Grechnyev 2017

#include <iostream>
#include <iomanip>
#include <string>

//==============================
// This is a simple ostream impementation of printf
// This one uses a fixed-size static buffer and
// does not support e.g. C++ strings without .c_str()
// Making a better one like Boost format() is much harder
template <typename...  Params>
void print(std::ostream & os, const std::string & fmt, Params... p) {
    constexpr size_t SIZE = 1000;
    static char buffer[SIZE];  // Hidden global buffer = ugly
    std::snprintf(buffer, SIZE, fmt.c_str(), p...);
    os << buffer;
}
//==============================
int main(){
    using namespace std;
    /*{
        cout << "Elementary use of cin, cout, cerr :" << endl;

        int a = 3;
        int b = 7;

        cout << "a = " << a << " , b = " << b << " , a*b = " << a*b << endl;

        string fileName("idiot.cfg");
        cerr << "[cerr example]Fatal error : file " << fileName << " not found ! \n";

        double c, d;
        cout << "Enter c, d :" << endl;
        cin >> c >> d;

        cout << "c = " << c << " , d = " << d << " , c*d = " << c*d << endl;

        // cin with string reads only one word (up to a whitespace)
        cout << "Enter your full name (e.g. Mary Ann Carter)\n";
        string name;
        cin >> name;
        cout << "You entered " << name << endl;
        getline(cin, name); // Read the rest of the line

        cout << "OOPS ! It didn't work as expected !\n\n";
        cout << boolalpha << cin.eof() << endl;
        cout << "Let's try again with getline() \n";
        cout << "Enter your full name (e.g. Mary Ann Carter)\n";
        getline(cin, name); // Read full line
        cout << "You entered " << name << endl;

        cout << "It's a good idea to read input streams with getline() !" << endl;

    }*/

    {
        cout << "ostream manipulators : \n";

        cout << "Flags : " << endl;
        // (no)boolalpha
        cout << "boolalpha: "
             << true << " " << boolalpha << true << noboolalpha << " "
             << false << " " << boolalpha << false << noboolalpha << endl;
        // (no)showbase -- see below
        // (no)showpoint
        cout << "showpoint: " << 3.0 << " " << showpoint << 3.0 << noshowpoint << endl;
        // (no)showpos
        cout << "showpos: " << 13 << " " << showpos << 13 << noshowpos << endl;
        // unitbuf = flush buffer after each write
        // uppercase (does NOT affect char/string !)
        cout << "uppercase: "<< 1.e30  << " "<< uppercase << 1.e30 << nouppercase << endl;
    }

    {
        cout << "print() : ostream version of printf() " << endl;

        print(cout, "8.1 = %10.13lf , 9 = %d \n", 8.1, 9);
    }

    return 0;
}
