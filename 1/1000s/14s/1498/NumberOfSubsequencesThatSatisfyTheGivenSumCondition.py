# https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=daily-question&envId=2025-06-29

class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        lengthOfNums=len(nums)
        modulo=1000000000+7
        powOfTwo=[]
        for i in range(0, lengthOfNums+1, 1):
            powOfTwo.append(1)
        for i in range(1, lengthOfNums, 1):
            powOfTwo[i]=powOfTwo[i-1]*2
            powOfTwo[i]%=modulo
        left=0
        right=lengthOfNums-1
        resultantSubsequences=0
        while(left<=right):
            if nums[left]+nums[right]<=target:
                resultantSubsequences+=powOfTwo[right-left]
                resultantSubsequences%=modulo
                left+=1
            else:
                right-=1
        return resultantSubsequences