# https://leetcode.com/problems/count-operations-to-obtain-zero/?envType=daily-question&envId=2025-11-09

class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        resultantMinNumberOfOperations=0
        while(True):
            if num1==0 or num2==0:
                break
            if num1>=num2:
                num1-=num2
            else:
                num2-=num1
            resultantMinNumberOfOperations+=1
        return resultantMinNumberOfOperations