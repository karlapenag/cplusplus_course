#include <iostream>
using namespace std;

const int myInt = 10; //global integer constant
int anotherInt = 30;  // global integer variable

int foo();

int main()
{
    cout << "myInt = " << myInt << endl; //reading of global constant permitted
    cout << "myInt occupies " << sizeof(myInt) << " bytes" << endl;
    //myInt = 19; //modification of a constant not permitted
    anotherInt = 25; //access to a global variable is permitted
    cout << "After modification in main, anotherInt = " << anotherInt << endl;

    bool found = true; // variable local to main

    foo();

    //myFloat = 2.5; // not recognized because not in scope

    {
        char myChar = 'a';
        cout << "Please enter a character: ";
        cin >> myChar;
        cout << "myChar = " << myChar << endl;
        cout << "myChar occupies " << sizeof(myChar) << " bytes" << endl;
    }
    //myChar = 'c'; // not recognized because not in scope
}

int foo()
{
    //found = false; // not recognized because it's not in scope

    double myFloat = 0.1; //variable local to foo
    cout << "myFloat = " << myFloat << endl;
    cout << "myFloat occupies " << sizeof(myFloat) << " bytes" << endl;

    anotherInt = 5; // access to a global variable permitted
    cout << "After modification in foo, anotherInt = " << anotherInt << endl;

}
