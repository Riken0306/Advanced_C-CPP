#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

class ComplexNumbers {
    // Complete this class
    int real;
    int complex;
    
    public:
        ComplexNumbers(int real, int complex){
            this->real = real;
            this->complex = complex;
        }
    
        void plus(ComplexNumbers c2){
            this->real += c2.real;
            this->complex += c2.complex;
        }
    
        void multiply(ComplexNumbers c2){
            int curr_real = this->real;
            int curr_complex = this->complex;
            this->real = curr_real*c2.real - curr_complex*c2.complex;
            this->complex = curr_real*(c2.complex) + curr_complex*(c2.real);
        }
    
        void print(){
            cout << real << " + i" << complex;
        }

};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }

}