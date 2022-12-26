//1-Encapsulation

//2-Inheritance

//3-Polymorphism
    //-Compile-time Polymorphism 
        //Function Overloading
        //Operator Overloading
            //Functions that only differ in return type cannot be Overloaded
    //-Runtime Polymorphism
        //Method Overriding(Creating methods with same name, arguments and return type in parent class and child class is Method Overriding)
        //Virtual Functions
            //Pointers to Direct Class
            //Base Class Pointer can point to Derived class object - "Its Legal !!!!"

//4-Abstraction(or Data Hiding)(Encapsulation leads to Abstraction)
    //Can be achived by access specifiers

//5-Abstract Classes and Interfaces
    //An interface describes the behavior or capabilities of a C++ class without committing to a particular implementation of that class.
    //The C++ interfaces are implemented using abstract classes. A class is made abstract by declaring at least one of its functions as pure virtual function. A pure virtual function is specified by placing "= 0"
    //Abstract classes cannot be instantiated 

//Classes that can be used to instantiate objects are called concrete classes

//6-Friend Class and Function
    // A friend function is a special function in C++ which in-spite of not being member function of a class has privilege to access private and protected data of a class

// A class declaration can contain static object of self type, it can also have pointer to self type, but it cannot have a non-static object of self type.


#include<iostream>
using namespace std;

//Encapsulation(Data Wrapping)
class Human
{
    private:
        int height;
        int weight;
        int age;

    public:
        int getAge(){
            return age;
        }
        void setAge(int age){
            this->age = age;
        }
};

//Inheritance
//Child Class
class Male : protected Human {
    public:
    string color;

    void sleep() {
        getAge();
        cout  << "Male Sleeping" << endl;
    }
};

//Multiple Inheritance
//Ambiguity(Problrm to solved in Inheritance)
//Passing parameter to Base Class's Constructor
class A{
    public: 
        int a;
        A(int a) {
            this->a = a;
            cout << "Class A Connstructor called" << endl;
        }
        //Method Overriding
        void abc() {
            cout << "Class A" << endl;
        }
};

class B{
    public: 
        int b;
        B(int b) {
            this->b = b;
            cout << "Class B Connstructor called" << endl;
        }

        //Method Overriding        
        void abc() {
            cout << "Class B" << endl;
        }
};

class C : public A, public B{
    public:
        int c;
        //This is how you pass parameters to base class's Constructor
        C(int c, int a, int b):A(a),B(b){
            this->c = c;
            cout << "Class C Connstructor called" << endl;
        }
        //Method Overriding
        void abc() {
            cout << "Class C" << endl;
        }
        void print(){
            cout << "[a b c] = " << a << " " << b << " " << c << endl;
        }
};

//Compile-time Polymorphism
//Operator Overloading
class Complex { 
    private: 
    int real, imag; 
    
    public: 
    Complex(int r = 0, int i = 0) { 
        real = r; imag = i; 
    }

    Complex operator + (Complex const & b) { 
        Complex a; 
        a.real = real + b.real; a.imag = imag + b.imag; 
        return a; 
    } 
    
    void print() { 
        cout << real << " + i" << imag << endl;  
    }

};


//Runtime Polymorphism
//Virtual Functions are used to overwrite default bhaviour that when BaseClassPointer is pointing to DerivedClassObject, methods from BaseClass Can only be accessed
class BaseClass {
    public:
        int var_base;
        virtual void display(){
            cout << "In Derived Class var_base = " << var_base << endl; 
        }
};

class DerivedClass: public BaseClass {
    public:
        int var_derived;
        void display(){
            cout << "In Derived Class var_base = " << var_base << endl; 
            cout << "In Derived Class var_base = " << var_derived << endl; 
        }
};

//Pure Virtual Functions
// Base class(Abstract Class)
class Shape {
   public:
      // pure virtual function providing interface framework.
      virtual int getArea() = 0;
      void setWidth(int w) {
         width = w;
      }
   
      void setHeight(int h) {
         height = h;
      }
   
   protected:
      int width;
      int height;
};
 
// Derived classes
class Rectangle: public Shape {
   public:
      int getArea() { 
         return (width * height); 
      }
};

class Triangle: public Shape {
   public:
      int getArea() { 
         return (width * height)/2; 
      }
};




//A function friendly to more than one class

class ABC;// forward declaration
 
class XYZ
{
    int x;
    public:
        void set_data(int a)
        {
            x=a;
        }
         
        friend void max(XYZ,ABC);
};
 
 
class ABC
{
    int y;
    public:
        void set_data(int a)
        {
            y=a;   
        }    
         
    friend void max(XYZ,ABC);
};
 
void max(XYZ t1,ABC t2)
{
    if(t1.x>t2.y)
        cout<<t1.x;
    else
        cout<<t2.y;
}

int main() {


    // int a=15, b=17, c=30;
    // C object(c, a, b);
    // object.print();
    
    // //The way you solve Ambigous problem
    // object.A::a = 10;
    // object.print();

    // Complex c1(10, 5), c2(2, 4); 
    // Complex c3 = c1 + c2; // "operator+" 
    // c3.print();

    // BaseClass *base_class_ptr;
    // BaseClass obj_base;
    // DerivedClass obj_derived;
    // base_class_ptr = &obj_derived;
    // base_class_ptr->var_base = 10;
    // // base_class_ptr->var_derived=10;
    // base_class_ptr->display();

    // Shape *shape; //(Since Shape is the abstract class, its object cannot be instanciated)
    // Shape *shape_ptr; //But its pointer can be initialzed
    // Rectangle rect_obj;
    // shape_ptr = &rect_obj;
    // shape_ptr->setHeight(10);
    // shape_ptr->setWidth(15);
    // int area = shape_ptr->getArea();
    // cout << area << endl;

    XYZ xyz;
    ABC abc;
    xyz.set_data(20);
    abc.set_data(35);
     
    max(xyz, abc);  //calling friend function
    return 0;






    return 0;
}

