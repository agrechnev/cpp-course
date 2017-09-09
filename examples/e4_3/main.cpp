// Example 4_3 : Diamond problem in multiple inheritance
// Created by Oleksiy Grechnyev 2017

#include <iostream>
using namespace std;
//=========================
// This example is shamelessly stolen from Wikipedia

class Animal {
public:
    virtual void eat() {
        cout << "Animal::eat()" << endl;
    }
};

// Two classes virtually inheriting Animal:
// If you change "public virtual" -> "public", it would not work
class Mammal : public virtual Animal {
public:
    virtual void breathe() {
        cout << "Mammal::breathe()" << endl;
    }
};

class WingedAnimal : public virtual Animal {
public:
    virtual void flap(){
        cout << "WingedAnimal::flap()" << endl;
    }
};

// A bat is still a winged mammal
class Bat : public Mammal, public WingedAnimal {
};
//=========================
int main(){

    cout << "Diamond problem and virtual inheritance demo:  \n\n";

    Bat b;

    b.eat();
    b.breathe();
    b.flap();

    return 0;
}
