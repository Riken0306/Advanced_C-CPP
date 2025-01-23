//Why Exception Handling?
//https://www.geeksforgeeks.org/exception-handling-c/

//try: Represents a block of code that can throw an exception.
//catch: Represents a block of code that is executed when a particular exception is thrown.
//throw: Used to throw an exception. Also used to list the exceptions that a function throws but doesn’t handle itself.

//If there is no catch block for exception thrown then it occurs into compilation error
//Default Exception which has no catch can be caught using catch(...)
//Whenever Exception is thrown, destructor of that class is called by default 
//try/catch blocks can be nested

#include<iostream>
using namespace std;

class Test {
public:
    Test() { cout << "Constructor of Test " << endl; }
    ~Test() { cout << "Destructor of Test " << endl; }
};

int main(){

    try {
        Test t1;
        cout << "Object Made" << endl;
        throw 10;
        cout << "After throw will never be executed" << endl;
    }
    catch (int i) {
        cout << "Caught " << i << endl;
    }

    return 0;
}