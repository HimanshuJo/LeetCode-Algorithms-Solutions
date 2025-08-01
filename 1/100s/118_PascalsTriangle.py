# https://leetcode.com/problems/pascals-triangle/description/?envType=daily-question&envId=2025-08-01

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        resultantTriangle=[]
        firstTriangle=[]
        firstTriangle.append(1)
        resultantTriangle.append(firstTriangle)
        if numRows==1:
            return resultantTriangle
        secondTriangle=[]
        secondTriangle.append(1)
        secondTriangle.append(1)
        resultantTriangle.append(secondTriangle)
        if numRows==2:
            return resultantTriangle
        for i in range(2, numRows, 1):
            currentTriangle=[]
            currentTriangle.append(1)
            prevTriangle=resultantTriangle[i-1]
            j=0
            while(True):
                if j+1>=len(prevTriangle):
                    break
                currentSum=prevTriangle[j]+prevTriangle[j+1]
                currentTriangle.append(currentSum)
                j+=1
            currentTriangle.append(1)
            resultantTriangle.append(currentTriangle)
        return resultantTriangle
