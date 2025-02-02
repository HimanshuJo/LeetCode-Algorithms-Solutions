# https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/?envType=daily-question&envId=2024-11-05

class Solution:
    def minChanges(self, s: str) -> int:
        lengthOfS=len(s)
        currentIndex=0
        currentNumberOfChanges=0
        while(True):
            if currentIndex>=lengthOfS:
                break
            currentSubString=""
            while(True):
                if len(currentSubString)>0 and len(currentSubString)%2==0 or currentIndex>=lengthOfS:
                    break
                if len(currentSubString)==0:
                    currentSubString+=s[currentIndex]
                    currentIndex+=1
                else:
                    if s[currentIndex]!=currentSubString[0]:
                        currentNumberOfChanges+=1
                        currentSubString+=currentSubString[0]
                        currentIndex+=1
                    else:
                        currentSubString+=currentSubString[0]
                        currentIndex+=1
        return currentNumberOfChanges
        