# https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22

class Solution:
    def findComplement(self, num: int) -> int:

        def toDecimal(currentString):
            sizeOfString=len(currentString)
            power=sizeOfString-1
            resultantDecimal=0
            print(currentString)
            for i in range(0, sizeOfString, 1):
                resultantDecimal+=int(currentString[i])*pow(2, power)
                power-=1
            return resultantDecimal

        def toBinary(num):
            if num==0:
                return "0"
            binaryNum=""
            while(num!=1):
                rem=num%2
                quo=num//2
                num=quo
                binaryNum+=str(rem)
            binaryNum+="1"
            binaryNum=binaryNum[::-1]
            return binaryNum

        numToBinary=toBinary(num)
        compliment=""
        lengthNumToBinary=len(numToBinary)
        for i in range(0, lengthNumToBinary, 1):
            if numToBinary[i]=='1':
                compliment+='0'
            else:
                compliment+='1'
        return toDecimal(compliment)