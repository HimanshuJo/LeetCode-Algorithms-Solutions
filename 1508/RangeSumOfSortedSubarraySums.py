# https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/?envType=daily-question&envId=2024-08-04s

class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        allSubArraySums=[]
        lengthOfNums=len(nums)
        modulus=1000000000+7
        resultantSum=0
        for i in range(0, lengthOfNums, 1):
            currentSubArraySum=0
            for j in range(i, lengthOfNums, 1):
                currentSubArraySum+=nums[j]
                currentSubArraySum%=modulus
                allSubArraySums.append(currentSubArraySum)
        allSubArraySums.sort()
        for i in range(left-1, right, 1):
            resultantSum+=allSubArraySums[i]
            resultantSum%=modulus
        return resultantSum