// Approach 1: Check all possible combinations of water's amount (min of two indices * distance b'w the indices) and return the max amount. Complexity: O(N^2)

class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        for (int i = 0; i < height.size() - 1; i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int amount = min(height[i], height[j]) * (j - i);
                result = max(result, amount);
            }
        }
        return result;
    }
};

// Approach 2: Use two pointers left and right. If their combination is greater than max, update max. We see that only min of two makes a difference
// so try to update the minimun along the way. If arr[left] < arr[right] then change left i.e., left++ else right--. Complexity: O(N)

class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int result = 0, left = 0, right = height.size() - 1;
        int amount;
        while (left < right)
        {
            amount = min(height[left], height[right]) * (right - left);
            result = max(amount, result);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return result;
    }
};
