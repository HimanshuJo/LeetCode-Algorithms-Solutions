# https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20

class Solution:
    def missingNumber(self, nums: List[int]) -> int:

        def binarySearch(nums, val):
            left=0
            right=len(nums)-1
            while(left<=right):
                mid=left+(right-left)//2
                if nums[mid]==val:
                    return True
                elif nums[mid]>val:
                    right=mid-1
                else:
                    left=mid+1
            return False

        def find(nums, val):
            return binarySearch(nums, val)

        nums.sort()
        sz=len(nums)
        for i in range(0, sz+1, 1):
            flag=find(nums, i)
            if flag==False:
                return i
        return -1