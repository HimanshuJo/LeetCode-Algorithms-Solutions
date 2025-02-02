# https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        sz=len(nums)
        res=[]
        for i in range(0, sz, 1):
            res.append(nums[i]*nums[i])
        res.sort()
        return res