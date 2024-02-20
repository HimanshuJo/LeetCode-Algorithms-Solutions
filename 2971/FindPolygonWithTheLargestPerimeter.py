# https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        sz=len(nums)
        for i in range(sz-1, -1, -1):
            curval=nums[i]
            cursm=0 
            for j in range(0, i, 1):
                cursm+=nums[j]
            if cursm>curval and (i-1)+1>=2:
                return cursm+curval
        return -1