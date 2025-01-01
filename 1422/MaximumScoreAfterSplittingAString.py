# https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2025-01-01

class Solution:
    def maxScore(self, s: str) -> int:

        def countZeros(currentString):
            lengthOfS=len(currentString)
            countZ=0
            for i in range(0, lengthOfS, 1):
                if currentString[i]=='0':
                    countZ+=1
            return countZ

        def countOnes(currentString):
            lengthOfS=len(currentString)
            countOn=0
            for i in range(0, lengthOfS, 1):
                if currentString[i]=='1':
                    countOn+=1
            return countOn

        lengthOfS=len(s)
        resultantMaxScore=0
        for i in range(0, lengthOfS, 1):
            currentString=""
            for j in range(i, lengthOfS, 1):
                currentString+=s[j]
                if j+1<=lengthOfS-1:
                    nextString=""
                    for k in range(j+1, lengthOfS, 1):
                        nextString+=s[k]
                    countLeft=countZeros(currentString)
                    countRight=countOnes(nextString)
                    resultantMaxScore=max(resultantMaxScore, countLeft+countRight)
        return resultantMaxScore