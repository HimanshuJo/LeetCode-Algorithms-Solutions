# https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10

class Solution:
    def clearDigits(self, s: str) -> str:

        def isDigit(digits, ch):
            if ch in digits:
                return True
            return False

        lengthOfS=len(s)
        digits={}
        digits['0']='0'
        digits['1']='1'
        digits['2']='2'
        digits['3']='3'
        digits['4']='4'
        digits['5']='5'
        digits['6']='6'
        digits['7']='7'
        digits['8']='8'
        digits['9']='9'
        while(True):
            if lengthOfS==0:
                break
            isDigitAvailable=False
            indexOfFirstDigit=-1
            for i in range(0, lengthOfS, 1):
                if isDigit(digits, s[i])==True:
                    s=s[:i]+'#'+s[i+1:]
                    indexOfFirstDigit=i
                    isDigitAvailable=True
                    break
            if isDigitAvailable:
                if indexOfFirstDigit-1>=0:
                    for i in range(indexOfFirstDigit-1, -1, -1):
                        if isDigit(digits, s[i])==False:
                            s=s[:i]+'#'+s[i+1:]
                            break
            if isDigitAvailable==False:
                break
            s=s.replace("#", "")
            lengthOfS=len(s)
        return s