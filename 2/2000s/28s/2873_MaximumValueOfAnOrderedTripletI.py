# https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/?envType=daily-question&envId=2025-04-02

class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        lengthOfNums=len(nums)
        longMinValue=-9223372036854775808
        resultantMaxValue=longMinValue
        for i in range(0, lengthOfNums, 1):
            if i+1<=lengthOfNums-1:
                for j in range(i+1, lengthOfNums, 1):
                    if j+1<=lengthOfNums-1:
                        for k in range(j+1, lengthOfNums, 1):
                            currentTripletValue=(nums[i]-nums[j])*nums[k]
                            if currentTripletValue>=0:
                                resultantMaxValue=max(resultantMaxValue, currentTripletValue)
        if resultantMaxValue!=longMinValue:
            return resultantMaxValue
        return 0
