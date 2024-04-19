# https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2024-03-24

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        sz=len(nums)
        prev=-1
        for i in range(0, sz, 1):
            if nums[i]==prev:
                return nums[i]
            prev=nums[i]
        return -1