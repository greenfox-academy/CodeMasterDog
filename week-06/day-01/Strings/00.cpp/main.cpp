#include <iostream>

using namespace std;

// Write a program that prints a few details to the terminal window about you
// It should print each detail to a new line.
//  - Your name
//  - Your age
//  - Do you like coffee? (as a boolen variable)
//
//  Example output:
//  John Doe
//  31
//  Likes coffee: true

int main()
{
    string name = "Laszlo Kovacs";
    int age = 35;
    bool likes_coffee = true;

    cout << name << endl;
    cout << age << endl;

    if (likes_coffee)
        cout << "Likes coffee: true" << endl;
    else
        cout << "Likes coffee: false" << endl;

    return 0;
}