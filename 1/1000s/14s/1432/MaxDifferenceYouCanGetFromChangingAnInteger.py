# https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/?envType=daily-question&envId=2025-06-15

class Solution:
    def maxDiff(self, num: int) -> int:
        numAsString=str(num)
        lengthOfString=len(numAsString)
        maxNumToBeFormed=-1*(1e9+10)
        minNumToBeFormed=1e9+10
        for i in range(lengthOfString-1, -1, -1):
            currentChar=numAsString[i]
            for i2 in range(0, 10, 1):
                newStringToBeFormed=''
                for i3 in range(0, lengthOfString, 1):
                    if numAsString[i3]!=currentChar:
                        newStringToBeFormed+=numAsString[i3]
                    else:
                        newStringToBeFormed+=str(i2)
                valToCheck=int(newStringToBeFormed)
                currentCharToCheck=newStringToBeFormed[0]
                if currentCharToCheck!='0':
                    maxNumToBeFormed=max(maxNumToBeFormed, valToCheck)
                    minNumToBeFormed=min(minNumToBeFormed, valToCheck)
        return maxNumToBeFormed-minNumToBeFormed