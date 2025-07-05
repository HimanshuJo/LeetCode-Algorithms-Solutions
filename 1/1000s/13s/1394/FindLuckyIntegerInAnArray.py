# https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=daily-question&envId=2025-07-05

class Solution:
    def findLucky(self, arr: List[int]) -> int:

        def isLucky(freqMap, val):
            if freqMap[val]==val:
                return True
            return False

        lengthOfArr=len(arr)
        freqMap={}
        for i in range(0, lengthOfArr, 1):
            if arr[i] in freqMap:
                freqMap[arr[i]]=freqMap[arr[i]]+1
            else:
                freqMap[arr[i]]=1
        maxLuckyNumber=-1
        for i in range(0, lengthOfArr, 1):
            if isLucky(freqMap, arr[i]):
                maxLuckyNumber=max(maxLuckyNumber, arr[i])
        return maxLuckyNumber