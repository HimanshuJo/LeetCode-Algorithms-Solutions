# https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01

class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        countOnes=0
        countZeros=0
        sz=len(s)
        for i in range(0, sz, 1):
            if s[i]=='0':
                countZeros+=1
            else:
                countOnes+=1
        res=""
        while(countOnes!=1):
            res=res+"1"
            countOnes-=1
        while(countZeros!=0):
            res=res+"0"
            countZeros-=1
        res=res+"1"
        return res