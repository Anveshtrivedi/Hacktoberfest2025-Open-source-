/*
  Problem Name: Longest Subarray with sum K.
Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
Intution: The concept of the prefix sum to solve this problem. Here, the prefix sum of a subarray ending at index i, simply means the sum of all the elements of that subarray.
In the map, we will store every prefix sum calculated, with the index(where the subarray with that prefix sum ends) in a <key, value> pair. Now, at index i, we just need to check the map data structure to get the index i.e. preSumMap[x-k] where the subarray with the prefix sum x-k ends. Then we will simply subtract that index i.e. preSumMap[x-k] from the current index i to get the length of the subarray with sum k i.e. len = i -preSumMap[x-k].
  */
  

code:
#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> a = { -1, 2, 4};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
