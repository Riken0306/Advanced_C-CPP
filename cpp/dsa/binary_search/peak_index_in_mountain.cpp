/*
852. Peak Index in a Mountain Array
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
Return the index of the peak element.
Your task is to solve it in O(log(n)) time complexity.

Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,10,5,2]
Output: 1
*/

#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int start=0, end=arr.size()-1, mid=0;

    while(start <= end) {
        mid = start + ((end - start) >> 1);
        if(arr[mid] < arr[mid+1]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return start;
}

int main() {

    vector<int> arr = {0,10,10,5,2};
    cout << "Peak Index in Mountain is: " << peakIndexInMountainArray(arr) << endl;

    return 0;

}

