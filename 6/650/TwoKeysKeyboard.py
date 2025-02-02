# https://leetcode.com/problems/2-keys-keyboard/description/?envType=daily-question&envId=2024-08-19

class Solution:
    def minSteps(self, n: int) -> int:

        def depthFirstSearch_forNumbers(n, beginString, oldPaste, memoization):
            if len(beginString)>n:
                return 2000000000
            if len(beginString)==n:
                return 0
            if (beginString, oldPaste) in memoization:
                return memoization[(beginString, oldPaste)]
            res=2000000000
            anotherString=beginString+oldPaste
            newPasteString=beginString+beginString
            stringWithOldPaste=1+depthFirstSearch_forNumbers(n, anotherString, oldPaste, memoization)
            stringWithNewPaste=2+depthFirstSearch_forNumbers(n, newPasteString, beginString, memoization)
            res=min(res, min(stringWithOldPaste, stringWithNewPaste))
            memoization[(beginString, oldPaste)]=res
            return memoization[(beginString, oldPaste)]

        if n==1:
            return 0
        beginString="A"
        oldPaste="A"
        memoization={}
        return depthFirstSearch_forNumbers(n, beginString, oldPaste, memoization)+1