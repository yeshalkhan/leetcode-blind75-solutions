// Approach 1: Make substrings from the given string and count no of characters. If a duplicate character is encountered, discard the substring and 
// check if count > max. Make substring from the next index and repeat. Complexity: O(N*max)

class Solution1 {
public:
    int makeSubstring(string s, int index)
    {
        unordered_set<char> mySet;
        int count = 0;
        for (int i = index; i < s.size(); i++)
        {
            if (mySet.count(s[i]) == 0)
            {
                mySet.insert(s[i]);
                ++count;
            }
            else 
                break;
        }
        return count;        
    }

    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int count;
        for (int i = 0; i < s.length(); i++)
        {
            count = makeSubstring(s, i);
            if (count > max)
                max = count;
        }
        return max;
    }
};
