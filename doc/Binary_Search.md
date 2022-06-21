# Binary Search

## 二分查找概念

## 二分查找例题

### [704. Binary Search](https://leetcode.cn/problems/binary-search/)

```c++
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        // Binary Search
        // [left, right], left <= right
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target)
            {
                // [left, middle - 1]
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                // [middle + 1, right]
                left = middle + 1;
            }
            else
            {
                // target = nums[middle]
                return middle;
            }
        }

        return -1;
    }
};
```

### [374. Guess Number Higher or Lower](https://leetcode.cn/problems/guess-number-higher-or-lower/)

```c++
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        int middle = left + ((right - left) / 2);

        while (guess(middle) != 0)
        {
            if (guess(middle) == -1)
                right = middle - 1;
            else
                left = middle + 1;
            middle = left + ((right - left) / 2);
        }

        return middle;
    }
};
```

### [35. Search Insert Position](https://leetcode.cn/problems/search-insert-position/)

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Binary Search
        // [left, right]
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target)
            {
                // [left, middle - 1]
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                // [middle + 1, right]
                left = middle + 1;
            }
            else
            {
                // target = nums[middle]
                return middle;
            }
        }

        return (right + 1);
    }
};
```

### [852 Peak Index in a Mountain Array](https://leetcode.cn/problems/peak-index-in-a-mountain-array/)

```c++
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Binary Search
        int left = 0;
        int right = arr.size() - 1;
        int mountainTop = 0;
        
        while (left <= right)
        {
            int middle = left + ((right - left) / 2);

            if (arr[middle] > arr[middle + 1]){
                mountainTop = middle;
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

    return mountainTop;
    }
};
```

### [367 Valid Perfect Square](https://leetcode.cn/problems/valid-perfect-square/)

```c++
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while (left <= right)
        {
            int middle = left + ((right - left) / 2);
            long square = (long) middle * middle;
            if (square < num)
            {
                left = middle + 1;
            } 
            else if (square > num)
            {
                right = middle - 1;
            } 
            else
            {
                return true;
            }
        }
        return false;
    }
};
```

