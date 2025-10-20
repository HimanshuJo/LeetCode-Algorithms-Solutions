# https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/?envType=daily-question&envId=2025-10-20

class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        resultantFinalValueOfX=0
        for i in range(0, len(operations), 1):
            currentOperation=operations[i]
            if currentOperation=="++X" or currentOperation=="X++":
                resultantFinalValueOfX+=1
            else:
                resultantFinalValueOfX-=1
        return resultantFinalValueOfX