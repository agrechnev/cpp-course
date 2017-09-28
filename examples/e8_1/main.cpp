// Example 8.1 : strings
// Created by Oleksiy Grechnyev 2017

#include <iostream>
#include <string>
//==============================
int main(){
    using namespace std;
    {
        cout << "\nConstructors :\n\n";

        // Literals and C-strings are 0-terminated
        // LIteral is a const char [] and NOT a string object !!!

        string s1("Bastard Sword");  // From a literal (const char [])
        cout << "s1 = " << s1 << endl;

        const char * cS = "Heavy Crossbow";   // From a C-string
        string s2(cS);
        cout << "s2 = " << s2 << endl;

        string s3(18, 'Z');  // 18 copies of char Z
        cout << "s3 = " << s3 << endl;

        string s4("Mary Had a Little Lamb", 8); // First 8 chars of a literal
        cout << "s4 = " << s4 << endl;

        string s5("Mary Had a Little Lamb" + 5, 12); // Adding int to literal moves position !
        cout << "s5 = " << s5 << endl;

        string s6(s1, 8);  // Take chars STARTING from position 8 in s1
        cout << "s6 = " << s6 << endl;

        string s7(s2, 6, 5);   // String, start, length
        cout << "s7 = " << s7 << endl;

        string s8; // Empty string

        // assing() sets an existing string constructor-like (many forms)
        s1.assign(s2, 6, 5);  // String, start, length
        cout << "s1 = " << s1 << endl;
    }

    {
        cout << "\nContainer operations :\n\n";


    }


    {
        cout << "\nString operation :\n\n";

        string s1 = "Take a look to the sky just before you die";
        cout << "s1 = " << s1 << endl;

        // substr
        cout << "s1.substr() = " << s1.substr() << endl;
        cout << "s1.substr(7) = " << s1.substr(7) << endl;
        cout << "s1.substr(7, 11) = " << s1.substr(7, 11) << endl;

        //c_str() ; Returns a 0-terminated C string
        // C-string return lives only as long as the string object alive and not modified !!!
        cout << "s1.c_str() = " << s1.c_str() << endl;
    }

    {
        cout << "\ninsert, delete :\n\n";

        // string has index-based insert, same syntax ans ctor and assign
        string s1 = "Lucy Liu";
        cout << "s1 = " << s1 << endl;

        s1.insert(5, "Alexis ");    // Insert substring before position 5
        cout << "s1 = " << s1 << endl;

        s1.insert(0, "Gorgeous ");    // Insert in the beginning (before 0)
        cout << "s1 = " << s1 << endl;

        s1.insert(s1.size(), 3, '!');    // Insert in the end, 3 times '!'
        cout << "s1 = " << s1 << endl;

        // Of course, iterator-based insert can be used as well

    }

    return 0;
}
