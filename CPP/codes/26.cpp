class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowIndex = 0;
        int numsLen = nums.size();
        for (int fastIndex = 1; fastIndex < numsLen; ++fastIndex)
        {
            if (nums[fastIndex] != nums[fastIndex-1])
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