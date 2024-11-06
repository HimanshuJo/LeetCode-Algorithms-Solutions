# https://leetcode.com/problems/find-if-array-can-be-sorted/description/?envType=daily-question&envId=2024-11-06

class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        
        def toBinary(number):
            resultantBinary=""
            while(number!=1):
                quotient=number//2
                remainder=number%2
                resultantBinary+=str(remainder)
                number=quotient
            resultantBinary+="1"
            return resultantBinary

        def swap(array, firstIndex, secondIndex):
            temporary=array[firstIndex]
            array[firstIndex]=array[secondIndex]
            array[secondIndex]=temporary

        def isAValidPair(firstNumber, secondNumber):
            binaryFirst=toBinary(firstNumber)
            binarySecond=toBinary(secondNumber)
            lengthFirst=len(binaryFirst)
            lengthSecond=len(binarySecond)
            countSetBits1=0
            countSetBits2=0
            for i in range(0, lengthFirst, 1):
                if binaryFirst[i]=='1':
                    countSetBits1+=1
            for i in range(0, lengthSecond, 1):
                if binarySecond[i]=='1':
                    countSetBits2+=1
            return countSetBits1==countSetBits2

        lengthOfNums=len(nums)
        temporary=[]
        for i in range(0, lengthOfNums, 1):
            temporary.append(nums[i])
        temporary.sort()
        for i in range(0, lengthOfNums, 1):
            if i-1>=0:
                for j in range(i, 0, -1):
                    current=nums[j]
                    previous=nums[j-1]
                    if current<previous:
                        if isAValidPair(current, previous):
                            swap(nums, j, j-1)
        return nums==temporary