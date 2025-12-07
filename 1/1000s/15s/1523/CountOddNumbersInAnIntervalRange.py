# https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/?envType=daily-question&envId=2025-12-07

class Solution:
    def countOdds(self, low: int, high: int) -> int:
        resultantCount=0
        if low&1:
            resultantCount+=1
        elif high&1:
            resultantCount+=1
        resultantCount+=((high-low)//2)
        return resultantCount