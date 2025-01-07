# https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07

class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:

        def checkForSubstring(stringToCheck, currentString):
            lengthCurrentString=len(currentString)
            for i in range(0, lengthCurrentString, 1):
                tempString=""
                for j in range(i, lengthCurrentString, 1):
                    tempString+=currentString[j]
                    if tempString==stringToCheck:
                        return True
            return False

        resultantList=[]
        lengthOfWords=len(words)
        for i in range(0, lengthOfWords, 1):
            stringToCheck=words[i]
            for j in range(0, lengthOfWords, 1):
                if i!=j:
                    currentString=words[j]
                    if len(stringToCheck)<=len(currentString):
                        isSubstring=checkForSubstring(stringToCheck, currentString)
                        if isSubstring==True:
                            resultantList.append(stringToCheck)
                            break
        return resultantList