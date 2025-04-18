# https://leetcode.com/problems/count-and-say/description/?envType=daily-question&envId=2025-04-18

class Solution:
    def countAndSay(self, n: int) -> str:
        resultantStringArr=[""]

        def genNextString(toPrcStringArr):
            toPrcString=toPrcStringArr[0]
            nwStringArr=[""]
            lengthOfStr=len(toPrcString)
            idx=0
            while(True):
                if idx>=lengthOfStr:
                    break
                currentChar=toPrcString[idx]
                currentCount=1
                while(True):
                    if idx>=lengthOfStr:
                        break
                    if idx+1<=lengthOfStr-1:
                        nextChar=toPrcString[idx+1]
                        if nextChar!=currentChar:
                            nwStringArr[0]+=str(currentCount)
                            nwStringArr[0]+=currentChar
                            idx+=1
                            break
                        else:
                            currentCount+=1
                            idx+=1
                    else:
                        nwStringArr[0]+=str(currentCount)
                        nwStringArr[0]+=currentChar
                        idx+=1
                        break
            return nwStringArr


        def depthFirstSearch_forStrings(n, beginString):
            if n==0:
                resultantStringArr[0]=beginString[0]
                return
            nextString=genNextString(beginString)
            depthFirstSearch_forStrings(n-1, nextString)
            return

        beginStringArr=["1"]
        depthFirstSearch_forStrings(n-1, beginStringArr)
        return resultantStringArr[0]