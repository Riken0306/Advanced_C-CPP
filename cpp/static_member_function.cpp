//Static Member Functions
    //Belongs to the class, not to any specific object.
    //Can be called using the class name or an object.
    //Can only access static members (both variables and functions) of the class.
    //Cannot directly access non-static members because it does not operate on a specific object.
//Staic Member Variables
    //It is defined and initialized outside the class
    //Static members have a lifetime equal to the program, unlike non-static members that are destroyed when the object is destroyed.

#include <iostream>

using namespace std;

class Counter {
private:
    static int count;
public:
    int getCount() { return count;}
    static void incrementCount() { count++; }
    static void decrementCount() { count--; }
};

// Definition and initialization of static member
// Mandatory because static members exist at the class level, not at the instance level.
int Counter::count = 0;

int main()
{
    Counter obj1, obj2, obj3;

    obj1.incrementCount();  // Increment count (count = 1)
    cout << "obj1: " << obj1.getCount() << endl;  // Output: 1

    obj2.incrementCount();  // Increment count (count = 2)
    cout << "obj2: " << obj2.getCount() << endl;  // Output: 2

    obj3.decrementCount();  // Decrement count (count = 1)
    cout << "obj3: " << obj3.getCount() << endl;  // Output: 1

    cout << "obj1: " << obj1.getCount() << endl;  // Output: 1
    cout << "obj2: " << obj2.getCount() << endl;  // Output: 1

    return 0;
}
