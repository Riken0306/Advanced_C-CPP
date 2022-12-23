//1-Encapsulation
//2-Inheritance
//3-Polymorphism
    //-Compile-time Polymorphism (Function Overloading and Operator Overloading)
        //Functions that only differ in return type cannot be Overloaded
    //-Runtime Polymorphism
        //Method Overriding(Creating methods with same name, arguments and return type in parent class and child class is Method Overriding)
        //Virtual Functions
//4-Abstraction 


//Pointers to Direct Class
//Base Class Pointer can point to Derived class object - "Its Legal !!!!"

#include<iostream>
using namespace std;

//Encapsulation(Data Hiding) - All Data Members are private
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

        //method Overriding        
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
        void abc() {
            cout << "Class C" << endl;
        }
        //Method Overriding
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

int main() {


    // int a=15, b=17, c=30;
    // C object(c, a, b);
    // object.print();
    
    // //The way you solve Ambigous problem
    // object.A::a = 10;
    // object.print();

    Complex c1(10, 5), c2(2, 4); 
    Complex c3 = c1 + c2; // "operator+" 
    c3.print();

    return 0;
}

