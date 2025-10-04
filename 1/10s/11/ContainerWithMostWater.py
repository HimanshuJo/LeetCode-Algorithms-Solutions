# https://leetcode.com/problems/container-with-most-water/?envType=daily-question&envId=2025-10-04

class Solution:
    def maxArea(self, height: List[int]) -> int:
        lengthOfHeight=len(height)
        resultantMaxAmountOfWater=2000000000*-1
        left=0
        right=lengthOfHeight-1
        while(left<=right):
            currAmountOfWaterStored=min(height[left], height[right])*(right-left)
            resultantMaxAmountOfWater=max(resultantMaxAmountOfWater, currAmountOfWaterStored)
            if height[left]<=height[right]:
                left+=1
            else:
                right-=1
        return resultantMaxAmountOfWater