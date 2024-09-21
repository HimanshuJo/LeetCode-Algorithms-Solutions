# https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2024-09-21

class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        allNumbersAsString=[]
        for i in range(1, n+1, 1):
            allNumbersAsString.append(str(i))
        allNumbersAsString.sort()
        resultantListLexicographicalNumbers=[]
        legnthOfFirstList=len(allNumbersAsString)
        for i in range(0, legnthOfFirstList, 1):
            resultantListLexicographicalNumbers.append(int(allNumbersAsString[i]))
        return resultantListLexicographicalNumbers