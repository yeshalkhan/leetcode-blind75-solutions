// Approach 1: Sort the array and use two pointers. Complexity : O(NlogN)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        vector<int> result(2);
        while(start <= end)
        {
            int sum = nums[start] + nums[end];
            if (sum == target)
            {  
               result[0] = nums[start];
               result[1] = nums[end];
               break;
            } 
            else if (sum < target)
                start++;
            else 
                end--;
        }
        return result;
    }
};

// Approach 2: Make a set and check if complement of sum and current element i.e., target-nums[i] exists in  
// the set. If it does, we've found the solution otherwise add current element to set. Complexity: O(N)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> s;
        int second_element;
        vector<int> result(2);
        for (int i = 0; i < nums.size() ; i++)
        {
            second_element = target - nums[i];
            if (s.count(second_element))
            {
                result[0] = nums[i];
                result[1] = second_element;
                break;
            }
            else
                s.insert(nums[i]);  
        }
        return result;
    }
};
