# https://leetcode.com/problems/count-symmetric-integers/description/?envType=daily-question&envId=2025-04-11

class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:

        def isASymmetricInteger(value):
            toCheckString=str(value)
            lengthOfStr=len(toCheckString)
            if lengthOfStr%2!=0:
                return False
            halfLength=lengthOfStr//2
            sumLeft=0
            sumRight=0
            i=0
            j=halfLength
            while(True):
                if i>=halfLength and j>=lengthOfStr:
                    break
                sumLeft+=int(toCheckString[i])
                sumRight+=int(toCheckString[j])
                i+=1
                j+=1
            if sumLeft==sumRight:
                return True
            return False

        resultantSymmNums=0
        while(low<=high):
            if isASymmetricInteger(low):
                resultantSymmNums+=1
            if low==high:
                break;
            if isASymmetricInteger(high):
                resultantSymmNums+=1
            low+=1
            high-=1
        return resultantSymmNums