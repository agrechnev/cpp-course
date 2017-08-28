// Created by Oleksiy Grechnyev 2017

// This is a comment
/* This is also a comment */

// Include the header file iostream (needed for file Input/Output)
#include <iostream>

/*
 The main() function is the program entry point
 can also be declared as main(int argc, char **argv) 
 returns int value, 0 for correct exit, 1 for error
 */
int main(){
    // std:: cout (standard output stream) and
    // std::endl (End of line) are members of namespace std
    // They are defined in iostream
    std::cout << "Carthago delenda est." << std::endl;
    
    // Return 0 = OK
    return 0;
}