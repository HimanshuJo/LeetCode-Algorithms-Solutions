# https://leetcode.com/problems/fruit-into-baskets/description/?envType=daily-question&envId=2025-08-04

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        lengthOfFruits=len(fruits)
        left=0
        right=0
        resultantMaxFruits=-1*10000000010
        basketMap={}
        for right in range(0, lengthOfFruits, 1):
            if fruits[right] in basketMap:
                basketMap[fruits[right]]+=1
            else:
                basketMap[fruits[right]]=1
            while(True):
                if len(basketMap)<=2:
                    break
                basketMap[fruits[left]]-=1
                if basketMap[fruits[left]]==0:
                    del(basketMap[fruits[left]])
                left+=1
            resultantMaxFruits=max(resultantMaxFruits, (right-left)+1)
        return resultantMaxFruits
