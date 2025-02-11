# https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2025-02-02

class Solution:
    def check(self, nums: List[int]) -> bool:

        def rotateRight(nums, positions):
            lengthOfNums=len(nums)
            resultantList=[]
            for i in range(0, lengthOfNums, 1):
                resultantList.append(-1)
            for i in range(0, lengthOfNums, 1):
                resultantList[(i+positions)%lengthOfNums]=nums[i]
            return resultantList

        tempNums=[]
        lengthOfNums=len(nums)
        for i in range(0, lengthOfNums, 1):
            tempNums.append(nums[i])
        tempNums.sort()
        for i in range(0, lengthOfNums, 1):
            tocheckNums=rotateRight(nums, i+1)
            if tocheckNums==tempNums:
                return True
        return False
        
        