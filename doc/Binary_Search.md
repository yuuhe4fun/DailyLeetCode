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

### [1385 Find the Distance Value Between Two Arrays](https://leetcode.cn/problems/find-the-distance-value-between-two-arrays/)

```c++
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int out = 0;
        for (int i = 0; i < arr1.size(); ++i)
        {
            bool flag = true;
            for (int j = 0; j < arr2.size(); ++j)
            {
                int distance = abs(arr1[i] - arr2[j]);
                if (distance <= d)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                out ++;
            }
        }

        return out;
    }
};
```

```c++
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for (auto &x: arr1) {
            bool ok = true;
            for (auto &y: arr2) {
                ok &= (abs(x - y) > d);  // ok = ok & (abs(x - y) > d);
            }
            cnt += ok;
        }
        return cnt;
    }
};
```

```c++
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (auto &x: arr1) {
            unsigned p = lower_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
            bool ok = true;
            if (p < arr2.size()) {
                ok &= (arr2[p] - x > d);
            }
            if (p - 1 >= 0 && p - 1 <= arr2.size()) {
                ok &= (x - arr2[p - 1] > d);
            }
            cnt += ok;
        }
        return cnt;
    }
};
```

### [69 Sqrt(x)](https://leetcode.cn/problems/sqrtx/)

```c++
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int squareRoot = 0;
        while (left <= right)
        {
            int middle = left + (right - left)/2;
            if ((long long)middle * middle > x)
            // if (x/middle < middle) 可以避免溢出
            {
                right = middle - 1;
            }
            else
            {
                squareRoot = middle;
                left = middle + 1;
            }
        }

        return squareRoot;
    }
};
```

### [744 Find Smallest Letter Greater Than Target](https://leetcode.cn/problems/find-smallest-letter-greater-than-target/)

```c++
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;
        int sLetter = 0;
        while (left <= right)
        {
            int middle = (left + right) >> 1;
            if (letters[middle] <= target)
            {
                left = middle + 1;
            }
            else
            {
                sLetter = middle;
                right = middle - 1;
            }
        }
        return (right == letters.size() - 1) ? letters[0] : letters[sLetter];
    }
};
```

### [278 First Bad Version](https://leetcode.cn/problems/first-bad-version/)

```c++
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int minBadVersion = 0;
        while (left <= right)
        {
            int middle = left + (right - left)/2;
            if (isBadVersion(middle))
            {
                minBadVersion = middle;
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return minBadVersion;
    }
};
```

