//Standard Template Library(STL) uses Generic Programming 

//Iterators
    //Iterators are used to point at the memory addresses of STL containers
    //Operators for iterators
        //begin(), end(), next(ptr, int), prev(ptr, int), inserter(container, ptr) 
    //const iterators:- Elements pointed by const iterators cannot be changed or modified

//Vectors
    //Iterator Functions
        //begin(), end(), cbegin(), cend()
    //Capacity Functions
        //size(), capacity(), resize(), shrink_to_fit()
    //Access Functions
        //at(), front(), back()
    //Modifiers
        //assign(), push_back(), pop_back(), insert(), erase(), swap(), clear()

#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

int main(){

    vector<int> arr;

    arr.assign(5, 10);

    for (int i = 1; i <= 10; i++)
        arr.push_back(i);
    
    //using pre-increment makes the operation bit faster
    //auto is used so that we don't need to define type of pointer of i
    for (auto i = arr.begin(); i != arr.end(); ++i){
        cout << *i << " ";
    }

    cout << endl;
    cout << arr.size() << " " << arr.capacity() << endl;
    arr.shrink_to_fit(); 
    cout << arr.size() << " " << arr.capacity() << endl;
   


    return 0;
}