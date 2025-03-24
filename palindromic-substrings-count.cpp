// Approach 1: Generate substrings and check if they're palindromic, Complexity: O(N^3)

class Solution1 {
public:
    bool isPalindrome(string s)
    {
        if (s.size() == 1)
            return true;
        int mid =  s.size() / 2;
        for (int i = 0, j = s.size() - 1; i < mid; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
                count += isPalindrome(s.substr(i, (j - i + 1)));
        }
        return count;
    }
};

// Approach 2: 
