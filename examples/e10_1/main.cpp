// Example 10.1 Operator overloading : class Vec2

#include <iostream>

#include "./Vec2.h"

using namespace std;

//==============================
int main() {
    {
        cout << "\nVec2 constructor, ==, !=, output :\n\n";

        Vec2 a(1.0, 2.0), b(1.0, 2.0), c(2.0, 1.0);

        //        cout << "Enter vector b :" << endl;
        //        cin >> b;

        // Assignment
        Vec2 d;
        d = c;

        // overloaded <<
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;

        // getters
        cout << "a.getX() = " << a.getX() << endl;
        cout << "a.getY() = " << a.getY() << endl;

        // overloaded ==, !=
        cout << boolalpha;
        cout << "(a == a) is " << (a == a) << endl;
        cout << "(a != a) is " << (a != a) << endl;
        cout << "(a == b) is " << (a == b) << endl;
        cout << "(a != b) is " << (a != b) << endl;
        cout << "(a == c) is " << (a == c) << endl;
        cout << "(a != c) is " << (a != c) << endl;
    }

    {
        cout << "\nVec2 comparison operators (compare x, then y) :\n\n";

        Vec2 a(1.0, 2.0), b(1.0, 1.0), c(2.0, 0.0);

        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;

        cout << "a < b :" << (a < b) << endl;
        cout << "a > b :" << (a > b) << endl;
        cout << "a <= b :" << (a <= b) << endl;
        cout << "a >= b :" << (a >= b) << endl;

        cout << "a <= a :" << (a <= a) << endl;
        cout << "a >= a :" << (a >= a) << endl;
        cout << "a < a :" << (a < a) << endl;
        cout << "a > a :" << (a > a) << endl;

        cout << "a < c :" << (a < c) << endl;
        cout << "a > c :" << (a > c) << endl;
        cout << "a <= c :" << (a <= c) << endl;
        cout << "a >= c :" << (a >= c) << endl;
    }

    {
        cout << "\nVec2 arithmetics :\n\n";

        Vec2 a(-1, 2), b(2, -1);
        a += b;   // 1 1
        cout << "a = " << a << endl;
        a -= b;    // Back to  -1 2
        cout << "a = " << a << endl;
        a *= 3.0;  // a = -3 6
        cout << "a = " << a << endl;
        a /= 3.0;   // Back to  -1 2
        cout << "a = " << a << endl;

        // More arithmetics
        Vec2 c = 2.0*a + b*3.0;    // 4 1
        cout << "c = " << c << endl;
        c = a*3.0 - b/0.5 + 2*Vec2{3, -5}; // -1 -2
        cout << "c = " << c << endl;

        // Finally, the unary minus
        c = -c;   // 1  2
        cout << "c = " << c << endl;
    }
    return 0;
}
