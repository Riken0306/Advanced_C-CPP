/*
34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
*/

#include <iostream>
#include <vector>

using namespace std;

//Brute-Force Approach
vector<int> searchRange(vector<int>& nums, int target) {

    vector<int> ans = {-1, -1};
    int start = 0, end = nums.size() - 1, mid =0;

    //Returnn if array is empty
    if (nums.empty()) {
        return ans;
    }

    //Find First Occurence
    while(start <= end) {
        mid = start + ((end - start) >> 1);

        if (nums[mid] == target) {
            ans[0] = mid;
            end = mid - 1;
        }
        else if(target > nums[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    //Return if First Occurence not Found
    if (ans[0] == -1) {
        return ans;
    }


    //Find Last Occurence
    start = ans[0];
    end = nums.size() - 1;

    while(start <= end) {
        mid = start + ((end - start) >> 1);
        if (nums[mid] == target) {
            ans[1] = mid;
            start = mid + 1;
        }
        else if(target > nums[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {

    vector<int> num = {5,7,7,8,8,10};
    int target = 8;

    vector<int> ans = searchRange(num, target);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;

}
