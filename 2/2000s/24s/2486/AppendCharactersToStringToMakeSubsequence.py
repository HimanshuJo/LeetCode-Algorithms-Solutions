# https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/?envType=daily-question&envId=2024-06-03

class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        minCharactersNeededToMakeTSubsequenceOfS=0
        sizeOfS=len(s)
        sizeOfT=len(t)
        currentTraversalIndexInS=-1
        for indexInT in range(0, sizeOfT, 1):
            currentCharacterAtIndexInT=t[indexInT]
            haveFoundCurrentCharacterAtIndexInTInS=False
            if currentTraversalIndexInS+1<=sizeOfS-1:
                for indexInS in range(currentTraversalIndexInS+1, sizeOfS, 1):
                    if s[indexInS]==currentCharacterAtIndexInT:
                        haveFoundCurrentCharacterAtIndexInTInS=True
                        currentTraversalIndexInS=indexInS
                        break
            if haveFoundCurrentCharacterAtIndexInTInS==False:
                minCharactersNeededToMakeTSubsequenceOfS+=(sizeOfT-indexInT)
                break
        return minCharactersNeededToMakeTSubsequenceOfS
            