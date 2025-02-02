# https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/?envType=daily-question&envId=2025-01-12

class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        lengthOfS=len(s)
        if lengthOfS%2!=0:
            return False
        openBracketsStack=[]
        unlockedIndicesStack=[]
        for i in range(0, lengthOfS, 1):
            if locked[i]=='0':
                unlockedIndicesStack.append(i)
            elif s[i]=='(':
                openBracketsStack.append(i)
            else:
                if len(openBracketsStack)>=1:
                    openBracketsStack.pop(0)
                elif len(unlockedIndicesStack)>=1:
                    unlockedIndicesStack.pop(0)
                else:
                    return False
        while(len(openBracketsStack)>=1 and len(unlockedIndicesStack)>=1 and openBracketsStack[0]<unlockedIndicesStack[0]):
            openBracketsStack.pop(0)
            unlockedIndicesStack.pop(0)
        if len(openBracketsStack)>=1:
            return False
        return True