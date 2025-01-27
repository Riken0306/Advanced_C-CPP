//Unique Pointers
    //unique_ptr stores one pointer only.
    //We can assign a different object by removing the current object from the pointer
//Shared Pointers
    //By using shared_ptr more than one pointer can point to this one object at a time
    //it’ll maintain a Reference Counter using the use_count() method.
//Weak Poinetrs
    //Weak_ptr is a smart pointer that holds a non-owning reference to an object
    //It’s similar to shared_ptr except it’ll not maintain a Reference Counter
    //The Idea is to avoid the circular dependency created by two or more object
    //pointing to each other using shared_ptr
    //A weak_ptr does not directly manage the lifetime of the object it points to.
    //Instead, it is used to observe a shared_ptr without increasing the reference count.
    //Because of this, you cannot directly dereference a weak_ptr like a shared_ptr.
    //weak_ptr does not have operator* or operator-> like shared_ptr because the object might have been deleted.
    //Instead, you must use lock(), which:
        //Returns a valid shared_ptr if the object is still alive.
        //Returns an empty shared_ptr if the object has been deleted.


#include <algorithm>
#include <iostream>
#include <memory>

using namespace std;

class Rectangle
{
    int length;
    int width;

    public:

    Rectangle(int length, int width) {
        this->length = length;
        this->width = width;
    }

    int area()
    {
        return length*width;
    }
};

int main()
{

    //Unique Pointer
    unique_ptr<Rectangle> P1(new Rectangle(10, 20));
    cout << "P1->area = " << P1->area() << endl;

    unique_ptr<Rectangle> P2;
    P2 = std::move(P1);

    cout << "P2->area = " << P2->area() << endl;

    //Shared Pointer
    shared_ptr<Rectangle> P3(new Rectangle(10, 5));
    cout << "P3->area = " << P3->area() << endl;

    shared_ptr<Rectangle> P4;
    P4 = P3;

    cout << "P3->area = " << P3->area() << endl;
    cout << "P4->area = " << P4->area() << endl;
    cout << "P3->use_count = " << P3.use_count() << endl;
    cout << "P4->use_count = " << P4.use_count() << endl;

    //Weak Pointer
    shared_ptr<Rectangle> P5(new Rectangle(15, 5));
    weak_ptr<Rectangle> P6(P5);

    cout << "P5->area = " << P5->area() << endl;

    // Access weak_ptr safely
    if (auto sp = P6.lock()) {
        cout << "P6->area = " << sp->area() << endl;
    } else {
        cout << "P6 is expired!" << endl;
    }



    return 0;

}
