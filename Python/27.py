class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        slowIndex = 0
        for fast_index in range(len(nums)):
            if val != nums[fast_index]:
                nums[slowIndex] = nums[fast_index]
                slowIndex += 1
        return slowIndex
