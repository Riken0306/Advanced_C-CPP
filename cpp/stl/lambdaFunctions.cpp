//Lambda Functions also known as functors are same as Arrow Functions in Javascript
//It can be defined as [](arguments){//code //return value}
//It can return anything as no return type is defined

//Will get into more details after learning STL

#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    size_t x = 0 ;
    std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const auto val = std::count_if(v.begin(), v.end(), 
                        [](int v) { return v > 2 && v <= 6;});

    cout << val;
        
    return val;                                        
}