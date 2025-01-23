/*
875. Koko Eating Bananas

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k.
Each hour, she chooses some pile of bananas and eats k bananas from that pile.
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//Brute-Force Approach
//Time-Complexity O(n*max_element)
//Possibly greater than O(n2) depends max_element
int minEatingSpeed_BruteForce(vector<int>& piles, int h) {

    int max_speed = *max_element(piles.begin(), piles.end());

    for(int k = 1; k < max_speed; k++) {
        int hours = 0;
        for(int i=0; i <= (int)piles.size(); i++) {
            hours += (piles[i]/k) + (piles[i]%k != 0);
        }

        if(hours <= h) {
            return k;
        }

    }

    return max_speed;
}

//Binary-Search on Answer
//Key Idea is to treat the solution space (possible answers) as a sorted range of integers
//And leverage binary search to narrow it down efficiently.
//Like k=1 to k=max_element is sorted, so apply binary search on it
//instead of traversing from 1 to max
int minEatingSpeed_BinarySearch(vector<int>& piles, int h) {
    long k_start = 1, k_end = *max_element(piles.begin(), piles.end()), k_mid;

    while(k_start <= k_end) {
        long hours = 0;
        k_mid = k_start + ((k_end - k_start) >> 2);

        for(auto pile : piles) {
            hours += (pile/k_mid) + (pile % k_mid != 0);
        }

        if(hours <= h) {
            k_end = k_mid - 1;
        }
        else {
            k_start = k_mid + 1;
        }
    }

    return (int)k_start;
}

int main() {

    //vector<int> piles = {3,6,7,11};
    //vector<int> piles = {30,11,23,4,20};
    vector<int> piles = {805306368,805306368,805306368};
    int h = 1000000000;

    //cout << "Brute Force k = " << minEatingSpeed_BruteForce(piles, h) << endl;
    cout << "Binary Search k = " << minEatingSpeed_BinarySearch(piles, h) << endl;

    return 0;
}
