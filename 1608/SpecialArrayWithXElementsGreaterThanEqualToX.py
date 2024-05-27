#   https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=daily-question&envId=2024-05-27

class Solution:
    def specialArray(self, nums: List[int]) -> int:

        def checkNumbersInNumsGreaterThanEqualToCurrentNumber(currentNumber, nums):
            lengthOfNums=len(nums)
            countOfNumbersGreaterThanEqualToCurrentNumber=0
            for i in range(0, lengthOfNums, 1):
                if nums[i]>=currentNumber:
                    countOfNumbersGreaterThanEqualToCurrentNumber+=1
            if countOfNumbersGreaterThanEqualToCurrentNumber==currentNumber:
                return True
            return False

        nums.sort()
        lengthOfNums=len(nums)
        lastNumberToCheck=nums[lengthOfNums-1]
        for currentNumber in range(0, lastNumberToCheck+1, 1):
            if checkNumbersInNumsGreaterThanEqualToCurrentNumber(currentNumber, nums):
                return currentNumber
        return -1