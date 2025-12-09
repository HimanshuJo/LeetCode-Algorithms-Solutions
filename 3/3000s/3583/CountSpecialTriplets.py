# https://leetcode.com/problems/count-special-triplets/description/?envType=daily-question&envId=2025-12-09

class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        lengthOfNums=len(nums)
        MOD=1000000000+7
        result=0
        leftCount=defaultdict(int)
        rightCount=defaultdict(int)
        for i in range(0, lengthOfNums, 1):
            currentVal=nums[i]
            rightCount[currentVal]+=1
        for j in range(0, lengthOfNums, 1):
            currentVal=nums[j]
            neededVal=currentVal*2
            rightCount[currentVal]-=1
            L=leftCount[neededVal]
            R=rightCount[neededVal]
            result=(result+(L*R)%MOD)%MOD
            leftCount[currentVal]+=1
        return result%MOD