# https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/?envType=daily-question&envId=2025-03-12

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        lengthOfNums=len(nums)
        countPositives=0
        countNegatives=0
        resultantMax=0
        for i in range(0, lengthOfNums, 1):
            if nums[i]==0:
                continue
            elif nums[i]>=1:
                countPositives+=1
            else:
                countNegatives+=1
            resultantMax=max(countPositives, countNegatives)
        return resultantMax
