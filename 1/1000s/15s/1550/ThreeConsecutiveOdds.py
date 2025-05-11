# https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2025-05-11

class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        lengthOfArr=len(arr)
        beginIndex=0
        while(True):
            if beginIndex+2>=lengthOfArr:
                break
            if arr[beginIndex]%2!=0 and arr[beginIndex+1]%2!=0 and arr[beginIndex+2]%2!=0:
                return True
            beginIndex+=1
        return False