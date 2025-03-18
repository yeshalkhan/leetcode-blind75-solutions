#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums)
            s.insert(n);
        int max = 0;
        int count = 0, smallest;
        for (int x : s)
        {
            if (s.count(x - 1) == 0)
            {
                count = 1;
                smallest = x;
                while (s.count(++smallest))
                    count++;
            }
            if (count > max)
                max = count;
        }
        return max;
    }
};
