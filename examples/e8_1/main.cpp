// Example 8.1 : strings
// Created by Oleksiy Grechnyev 2017

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <set>
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

        string s9 = "Baron of Hell";   // Assignment, also works for implicit conversion
        cout << "s9 = " << s9 << endl;

        // assing() sets an existing string constructor-like (many forms)
        s3.assign(s2, 6, 5);  // String, start, length
        cout << "s3 = " << s3 << endl;
    }


    {
        cout << "\nString operation :\n\n";

        string s1 = "Take a look to the sky just before you die";
        cout << "s1 = " << s1 << endl;

        cout << "s1.size() = " << s1.size() << endl;
        cout << "s1.length() = " << s1.length() << endl;

        // substr
        cout << "s1.substr() = " << s1.substr() << endl;
        cout << "s1.substr(7) = " << s1.substr(7) << endl;
        cout << "s1.substr(7, 11) = " << s1.substr(7, 11) << endl;

        //c_str() ; Returns a 0-terminated C string
        // C-string return lives only as long as the string object alive and not modified !!!
        cout << "s1.c_str() = " << s1.c_str() << endl;

        // Get the raw data (might be not 0-terminated !!!)
        const char * raw = s1.data();
    }


    {
        cout << "\nContainer operations :\n\n";

        string s = "Who's to say where the wind will take you";

        // Print with a range for
        for (char c : s)
            cout << c;
        cout << endl;

        // Modify with a range for
        for (char & c : s)
            c = toupper(c);

        // Print with an iterator
        for (auto it = s.cbegin(); it != s.cend(); ++it)
            cout << *it;
        cout << endl;

        // All algorithms can be used on strings
        // Sort
        sort(s.begin(), s.end());
        cout << s << endl;
    }

    {
        cout << "\ncapacity, push_back(), reserve :\n\n";

        string s;
        for (int i = 0; i<65; ++i){
            cout << "size = " << s.size() << " , capacity = " << s.capacity() << endl;
            s.push_back('Z');
        }

        // We get 15, 30, 60, 120 ...
        // 15 is the local capacity (stored in-place)
        // If more than 15 chars, we'll need HEAP

        s.reserve(100); // Reserve space

        s.shrink_to_fit(); // Shrink
        cout << "\nAfter shrink :\n";
        cout << "s = " << s << endl;
        cout << "size = " << s.size() << " , capacity = " << s.capacity() << endl;

        s.resize(27);   // Resize
        cout << "\nAfter resize :\n";
        cout << "s = " << s << endl;
        cout << "size = " << s.size() << " , capacity = " << s.capacity() << endl;

        s.clear();
        cout << "\nAfter clear :\n";
        cout << "s = " << s << endl;
        cout << "size = " << s.size() << " , capacity = " << s.capacity() << endl;


        s.clear();   // Remove everything, capacity=65 still !
        cout << "\nAfter clear :\n";
        cout << "s = " << s << endl;
        cout << "size = " << s.size() << " , capacity = " << s.capacity() << endl;

        s.shrink_to_fit(); // Shrink again, we get back to size = 0, capacity=15 !
        cout << "\nAfter shrink :\n";
        cout << "s = " << s << endl;
        cout << "size = " << s.size() << " , capacity = " << s.capacity() << endl;
    }

    {
        cout << "\ninsert, erase :\n\n";

        // string has index-based insert, same syntax as ctor and assign
        string s1 = "Lucy Liu";
        cout << "s1 = " << s1 << endl;

        s1.insert(5, "Alexis ");    // Insert substring before position 5
        cout << "s1 = " << s1 << endl;

        s1.insert(0, string("One Gorgeous Two"), 4, 9);    // Insert in the beginning (before 0)
        cout << "s1 = " << s1 << endl;

        s1.insert(s1.size(), 3, '!');    // Insert in the end, 3 times '!'
        cout << "s1 = " << s1 << endl;

        // Of course, iterator-based insert can be used as well
        // It only works with char, lists and iterators, no strings!
        auto pos = s1.begin() + 9;
        pos = s1.insert(pos, '?') + 1;
        cout << "s1 = " << s1 << endl;

        string s2(" Deadly ");
        s1.insert(pos, s2.cbegin(), s2.cend());
        cout << "s1 = " << s1 << endl;

        s1.erase(0, 18);   // pos, length to delete
        cout << "s1 = " << s1 << endl;

        pos = s1.begin() + 5;
        s1.erase(pos, pos + 7);  // Erase with iterators
        cout << "s1 = " << s1 << endl;

        s1.erase(8);
        cout << "s1 = " << s1 << endl;
    }

    {
        cout << "\n+, +=, append(), replace() :\n\n";

        string s1 = string("One ") + "Two " + "Three";      // OK
        cout << "s1 = " << s1 << endl;
        string s2 = "One " + string("Two ") + "Three";      // OK
        cout << "s2 = " << s2 << endl;
        string s3 = "One " + ("Two " + string("Three"));    // OK
        cout << "s3 = " << s3 << endl;
//        string s4 = "One " + "Two " + string("Three");      // Error
//        string s4 = "One " + "Two " + "Three";              // Error


        string s = "Alpha ";
        cout << "s = " << s << endl;

        // Append in the end
        s.append("Beta ");
        cout << "s = " << s << endl;
        // Append a substring of a C-string
        s.append("Gamma Delta ", 6);
        cout << "s = " << s << endl;

        // += works like append
        s += "Epsilon ";
        cout << "s = " << s << endl;

        // Replace works like erase, then insert
        s.replace(6, 4, "OMEGA");
        cout << "s = " << s << endl;
    }

    {
        cout << "\nfind() :\n\n";

        string s("Gorgeous ? Deadly Lucy Alexis Liu!!!");
        cout << "s = " << s << endl;
        cout << "s.size() = " << s.size() << endl;


        auto result = s.find("Alex");  // string::size_type actually
        cout << "s.find(\"Alex\") = " << result << endl;

        // Find a substring
        result = s.find("Alexander", 5);
        cout << "s.find(\"Alexander\", 5) = " << result << endl;  // npos
        if (string::npos == result)
            cout << "Not found !!!" << endl;

        cout << "s.find(\" L\") = " << s.find(" L") << endl;   // Find first
        cout << "s.rfind(\" L\") = " << s.rfind(" L") << endl; // Find last

        // Find first of characters
        cout << "s.find_first_of(\".,?!;;\") = " << s.find_first_of(".,?!;;") << endl;
        // Or last
        cout << "s.find_last_of(\".,?!;;\") = " << s.find_last_of(".,?!;;") << endl;

        // Find first not of characters
        cout << "s.find_first_not_of(\".,?!;;\") = " << s.find_first_not_of(".,?!;;") << endl;
        // Or last
        cout << "s.find_last_not_of(\".,?!;;\") = " << s.find_last_not_of(".,?!;;") << endl;


        cout << "\nALgorithm std::find() :\n";
        // Algorithm searches work for string but are less convenient
        auto it = find(s.cbegin(), s.cend(), 'L');  // Function, not method !
        cout << it - s.cbegin() << endl;

        it = find_if(s.cbegin(), s.cend(), [](char c)->bool{
            return set<char>{'?','!', '.', ',', ':', ';'}.count(c);
        });
        cout << it - s.cbegin() << endl;

        const string s2("Alex");  // Search for Alex with algorithms
        it = search(s.cbegin(), s.cend(), s2.cbegin(), s2.cend());
        cout << it - s.cbegin() << endl;

        const string s3(".,?!;;");  // Search for any of the ".,?!;;" with algorithms
        it = find_first_of(s.cbegin(), s.cend(), s3.cbegin(), s3.cend());
        cout << it - s.cbegin() << endl;
    }
    return 0;
}
