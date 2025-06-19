# https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/?envType=daily-question&envId=2025-06-19

class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        lengthOfNums=len(nums)
        resultantMinSubSeq=0
        prevMin=nums[0]
        for i in range(0, lengthOfNums, 1):
            if nums[i]-prevMin>k:
                resultantMinSubSeq+=1
                prevMin=nums[i]
        return resultantMinSubSeq+1