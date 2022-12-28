//Template class and Functions can be used 

#include<iostream>
using namespace std;

//Template Function
template <typename T> T myMax(T x, T y){
    return x > y ? x : y;
}

//Template Class with default argument
template <class T, class U = char> class A {
public:
    T x;
    U y;
    A() { cout << "Constructor Called " << sizeof(T) << " " << sizeof(U) << endl; }
};

int main(){
    cout << myMax<int>(3, 7) << endl;
    cout << myMax<char>('a', 'A') << endl;
    A<float, int> a;
}