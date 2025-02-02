# https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02

class Solution:
    def findMaxK(self, nums: List[int]) -> int:

        def customSearch(nums, val):
            left=0
            right=len(nums)-1
            while(left<=right):
                if nums[left]==-val:
                    return True
                elif nums[right]==-val:
                    return True
                left+=1
                right-=1
            return False

        nums.sort()
        sz=len(nums)
        for i in range(sz-1, -1, -1):
            curr=nums[i]
            if curr>=0:
                flag=customSearch(nums, curr)
                if flag==True:
                    return curr
        return -1