/*
https://leetcode.com/problems/water-bottles-ii/?envType=daily-question&envId=2025-10-02
*/

class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        currentFullBottles=numBottles
        currentEmptyBottles=0
        resultantBottlesDrink=0
        while(True):
            if currentFullBottles==0 and currentEmptyBottles<numExchange:
                break
            if currentEmptyBottles>=numExchange:
                currentFullBottles+=1
                currentEmptyBottles-=numExchange
                numExchange+=1
            else:
                currentEmptyBottles+=currentFullBottles
                resultantBottlesDrink+=currentFullBottles
                currentFullBottles=0
        return resultantBottlesDrink