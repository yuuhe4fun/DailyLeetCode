class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        int numsLen = nums.size();
        for (int fastIndex = 0; fastIndex < numsLen; fastIndex++)
        {
            if (nums[fastIndex] != 0)
            {
                nums[slowIndex++] = nums[fastIndex];
            }
        }

        while (slowIndex < numsLen)
        {
            nums[slowIndex] = 0;
            slowIndex++;
        };

    }
};