// Example 1_2 : Introducing classes, vectors.
// This is example demonstrates many C++ features at a glance, I'll explain them in detail later.
// Created by Oleksiy Grechnyev 2017

// Header iostream (file Input/Output)
#include <iostream>
// Header vector (class std::vector)
#include <vector>
// Header string (class std::string)

// This is the global scope. Functions, classes, global data can be declared here.

/** @brief A heroic brave superhero ultra-violent warrior
 *
 * This is a doxygen-style comment. If your code has lots of these,
 * you can generate doxygen docs out of it. You must have doxygen installed, of course.
 *
 * Put some description of the class here.
 * Here we define our class in the file main.cpp which also has the function main().
 * Usually people put every class into a separate pair of files, like Warrior.h, Warrior.cpp
 */
class Warrior {
public:  // Public stuff goes here
    /** @brief Constructor
     *
     * Note the construction const std::string &name,
     * It passes the string 'name' by reference to avoid copying
     * But as it is const, it cannot be modified
     * This is common for class types, not needed (but wouldn't hurt) for a primitive 'int age'
     *
     * @param[in] name
     * @param[in] weapon
     * @param[in] age
     */
    Warrior(const std::string &name, const std::string &weapon, int age) :
            name(name),  // Init class field 'name' with argument 'name'
            weapon(weapon),
            age(age) {
        // Calls own method str()
        std::cout << "Constructor : " << str() << std::endl;
    }

    /// Convert this object to string, declared here, defined below
    std::string str() const;

    /// Getters to get a private field, return a const reference
    const std::string &getName() const {
        return name;
    }

    const std::string &getWeapon() const {
        return weapon;
    }

    int getAge() const {
        return age;
    }

private: // Private stuff goes here
    /// Warrior's name (short doxygen comment with three '/')
    std::string name;

    /// Warrior's weapon
    std::string weapon;

    /// Warrior's Age
    int age;
}; // Note the semicolon ';' here, it's important !

// You can define class methods outside of class definition
std::string Warrior::str() const{
    return "name = " + name + ", weapon = " + weapon + ", age = " + std::to_string(age);
}

//=============================================

/** @brief Function main()
 *
 * This is another doxygen-style comment.
 *
 * @param[in] argc  Number of comand-line agruments + program name
 * @param[in] argv  Program name + comand-line agruments
 * @return          0 if successful, 1 if error
 */
int main(int argc, char **argv){
    // Allows to use names from namespace std, such as 'cout' or 'vector', without prefix 'std::'
    using namespace std;
    
    // Print program name and command-line arguments using a for loop. Arrays and vectors always start with 0 in C++ !
    // Note: C++ does NOT check for index out of range !
    // argv[666] will give undefined behavior, usually a segmentation fault !
    cout << "argc = " << argc << endl << endl;
    for (int i = 0; i < argc; ++i)
        cout << "argv[" << i << "] = " << argv[i] << endl;

    cout << endl; // Skip a line
    // Now let's create a vector of warriors, initializing with a list
    vector<Warrior> warriors{
            {"Brianna", "Lightsaber", 17},  // Initialize each warrior with a list
            {"Sita", "Spear", 15},
            {"Jean Grey", "Telekinesis", 25},
            Warrior("Ashe", "Zodiac Spear", 19) // Or a traditional constructor
    };

    // Add some more warriors
    warriors.emplace_back("Jaheira", "Club+5", 110); // Construct in-place. Best !
    Warrior wz("Zoe Maya Castillo", "Fists", 20);
    warriors.push_back(wz); // OOPS! A copy operation!
    warriors.push_back(move(Warrior("Casca", "Sword", 24))); // move operation : a bit better !

    cout << endl;
    cout << "WARRIORS (range for loop):" << endl;
    cout << endl;

    // Print all warriors using a range-for loop.
    // Again, I use a const reference (const Warrior &) to avoid copying objects
    for (const Warrior & w: warriors)
        cout << w.str() << endl;

    // Print them again with a traditional for loop
    cout << endl;
    cout << "WARRIORS (traditional for loop):" << endl;
    cout << endl;

    for (int i = 0; i < warriors.size(); ++i)
        cout << warriors[i].str() << endl;

    return 0;
}