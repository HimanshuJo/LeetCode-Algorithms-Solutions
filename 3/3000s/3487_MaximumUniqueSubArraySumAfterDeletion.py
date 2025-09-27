# https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/submissions/1710704160/?envType=daily-question&envId=2025-07-25

class Solution:
    def maxSum(self, nums: List[int]) -> int:
        resultantMaxSum=0
        maxNumber=-1*1000000010
        uniqueNumbers=set()
        numsLength=len(nums)
        for i in range(0, numsLength, 1):
            uniqueNumbers.add(nums[i])
            maxNumber=max(maxNumber, nums[i])
        isAnyPositive=False
        for val in uniqueNumbers:
            if val>=0:
                isAnyPositive=True
                resultantMaxSum+=val
        if isAnyPositive==False:
            return maxNumber
        return resultantMaxSum
