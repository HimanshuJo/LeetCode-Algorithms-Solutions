# https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/?envType=daily-question&envId=2024-09-14

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        lengthOfNums=len(nums)
        maxPossibleBitwiseAndInNums=-1
        for i in range(0, lengthOfNums, 1):
            maxPossibleBitwiseAndInNums=max(maxPossibleBitwiseAndInNums, nums[i])
        maxLength=0
        currentLengthOfSubarray=0
        for i in range(0, lengthOfNums, 1):
            if nums[i]==maxPossibleBitwiseAndInNums:
                currentLengthOfSubarray+=1
                maxLength=max(maxLength, currentLengthOfSubarray)
            else:
                currentLengthOfSubarray=0
        return maxLength