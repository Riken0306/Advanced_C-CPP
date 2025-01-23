#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& arr, int target) {
    int start = 0, end = (int)arr.size()-1, mid;

    while(start <= end) {
        mid = start + ((end - start) >> 1);

        if(target > arr[mid]) {
            start = mid + 1;
        }
        else if(target < arr[mid]) {
            end = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int main() {

    vector<int> even = {-1, 10, 15, 17, 18, 20};
    vector<int> odd = {-1};
    int target;

    cout << "Enter the target: ";
    cin >> target;

    cout << "In Array even Found " << target << " at Index = " << binary_search(even, target) << endl;
    cout << "In Array odd Found " << target << " at Index = " << binary_search(odd, target) << endl;

    return 0;
}
