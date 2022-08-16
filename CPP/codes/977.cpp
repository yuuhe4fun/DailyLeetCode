class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int numsLen = nums.size();
        vector<int> ans(numsLen);
        for (int i = 0, j = numsLen - 1, posIndex = numsLen - 1; i <= j;)
        {
            if (nums[i] * nums[i] > nums[j] * nums[j])
            {
                ans[posIndex] = nums[i] * nums[i];
                ++i;
            }
            else
            {
                ans[posIndex] = nums[j] * nums[j];
                --j;
            }
            --posIndex;
        }
        return ans;
    }
};