#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
}

int getMax(int arr[], int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        max = std::max(max, arr[i]);
    }

    return max;
}

int getMin(int arr[], int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        min = std::min(min, arr[i]);
    }

    return min;
}

int getSum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

bool linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
        if (key == arr[i])
            return 1;
    return 0;
}

void reverseArray(int arr[], int size)
{
    for (int i = 0, j = size - 1; i < j; i++, j--)
        swap(arr[i], arr[j]);
}

void swapAlternate(int arr[], int size)
{
    for (int i = 0; i < size - 1; i = i + 2)
    {
        swap(arr[i], arr[i + 1]);
    }
}

// O(n^2)
//  bool uniqueOccurences(int arr[], int size)
//  {
//      std::sort(arr, arr + size);

//     // printArray(arr, size);

//     int occurences[size], j = 0;
//     std::fill_n(occurences, size, 1);
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == arr[i + 1])
//         {

//             occurences[j] += 1;
//         }
//         else
//             j = j + 1;
//     }
//     printArray(occurences, j);

//     for (int i = 0; i < j; i++)
//     {
//         for (int k = 0; k < j; k++)
//         {
//             if (occurences[i] == occurences[k] && i != k)
//             {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// O(N LogN)
bool uniqueOccurences(int arr[], int size)
{

    int freq[2002];
    std::fill_n(freq, 2002, 1001);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            int negativeIndex = abs(arr[i]) + 1000;
            freq[negativeIndex]++;
        }
        else
            freq[arr[i]]++;
    }
    std::sort(freq, freq + 2002);

    for (int i = 1; i < 2002; i++)
    {
        if (freq[i] == freq[i - 1] && freq[i] != 1001)
            return false;
    }
    return true;
}

void findDuplicate(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = arr[i] - 1;

    for (int i = 0; i < size; i++)
        arr[arr[i] % size] += size;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= size * 2)
            cout << i + 1 << " ";
    }
}

// ARRAY IS ALWAYS PASS BY REFERENCE
int main()
{
    int array[15], size;

    // To fill whole array with one value
    //  std::fill_n(array, 15, -1);

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    // cout << sizeof(array) / sizeof(int) << endl;
    // printArray(array, size);

    // int max = getMax(array, size);
    // cout << "Max=" << max << endl;

    // int min = getMin(array, size);
    // cout << "Min=" << min << endl;

    // int sum = getSum(array, size);
    // cout << "Sum=" << sum << endl;

    // int search;
    // cin >> search;
    // bool search_result = linearSearch(array, size, search);
    // cout << search_result;

    // swapAlternate(array, size);
    // printArray(array, size);

    // bool check = uniqueOccurences(array, size);
    // cout << check;

    findDuplicate(array, size);
}

// PROBLEMS
/*
1) Find Unique ==> https://www.codingninjas.com/codestudio/problems/find-unique_625159
2) Unique No. of Occurences ==> https://leetcode.com/submissions/detail/779596767/
3) Find Duplicate ==> https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397
4) Find All Duplicates in an Array ==> https://leetcode.com/submissions/detail/779869187/
5) Pair Sum ==> https://www.codingninjas.com/codestudio/problems/pair-sum_697295?
6) Triplet Sum ==> https://www.codingninjas.com/codestudio/problems/triplets-with-given-sum_893028
7) Sort 0 1 2 ==> https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055
*/


/*
	// Triplet Sum.
    // O(N^3) goes into TLE
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k]==K){
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    sort(temp.begin(), temp.end());
                    if(find(ans.begin(),ans.end(),temp)==ans.end())
                        ans.push_back(temp);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;

    // ==> Things Learned -> std::find -> https://www.geeksforgeeks.org/std-find-in-cpp/
*/

/*

	// Triplet Sum.
    // >O(N^2)
    // Solved using 2-pointer approach inside a loop

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        int left=i+1, right=n-1;
        
        while(left<right){
             if(arr[i]+arr[left]+arr[right]==K){
                ans.push_back({arr[i], arr[left], arr[right]});
                int x = arr[left];
                int y = arr[right];
                while(left<right && arr[left] == x)
                    left++;
                while(left<right && arr[right] ==y)
                    right--;
                }
            else if(arr[i]+arr[left]+arr[right]<K)
                left++;
            else
                right--;
        }
        while(i+1<n && arr[i]==arr[i+1])
            i++;
    }
    sort(ans.begin(), ans.end());
    return ans;  
*/