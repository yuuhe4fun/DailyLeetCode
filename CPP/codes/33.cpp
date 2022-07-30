/*  将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。
*   此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。
*   就这样循环。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return -1;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        int lValue = 0;
        int rValue = 0;
        int mValue = 0;
        
        while (left <= right)
        {
            mid = left + (right - left) / 2;

            lValue = nums[left] ;
            mValue = nums[mid]  ;
            rValue = nums[right];

            if (mValue == target)
            {
                return mid;
            }
            else if (mValue >= lValue)
            {
                if (lValue <= target && target < mValue)
                {
                    right = mid - 1;
                }
                else
                {
                    left = left + 1;
                }
            }
            else
            {
                if (mValue < target && target <= rValue)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

        }
        return -1;
    }
};