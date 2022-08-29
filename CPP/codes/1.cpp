class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numsLen = nums.size();
        for (int i = 0; i < numsLen; ++i)
        {
            for (int j = i + 1; j < numsLen; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};