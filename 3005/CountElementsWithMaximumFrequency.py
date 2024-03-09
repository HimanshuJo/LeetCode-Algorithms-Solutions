# https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2024-03-08

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        mp1={}
        mp2={}
        sz=len(nums)
        for i in range(0, sz, 1):
            if nums[i] in mp1:
                mp1[nums[i]]+=1
            else:
                mp1[nums[i]]=1
        for [key, vals] in mp1.items():
            if vals in mp2:
                curr=mp2[vals]
                curr.append(key)
                mp2[vals]=curr
            else:
                nwarl=[]
                nwarl.append(key)
                mp2[vals]=nwarl
        grtFreq=max(mp2)
        eles=len(mp2[grtFreq])
        return grtFreq*eles