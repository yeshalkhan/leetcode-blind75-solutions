// Time complexity: O(N)
// Alternative approach is to sort the array and count length of each sequence and return the max, then complexity: O(NlogN)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums)
            s.insert(n);
        int max = 0, count = 0;
        for (int x : s)
        {
            if (s.count(x - 1) == 0)    // check if current element is the smallest in its sequence i.e., x-1 doesn't exist
            {
                count = 1;
                while (s.count(++x))
                {
                    count++;
                    s.erase(x);    // remove element to avoid recomputation
                }
            }
            if (count > max)
                max = count;
        }
        return max;
    }
};

