/*
https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2024-07-07
*/

/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var numWaterBottles = function(numBottles, numExchange) {
    let maxNumberBottlesToDrink=0, currentExtraNumberBottlesToDrink=0, currentEmptiedBottles=0;
    maxNumberBottlesToDrink+=numBottles, currentEmptiedBottles+=numBottles;
    while(true){
        if(currentEmptiedBottles<numExchange) break;
        let recentEmptiedBottles=0;
        while(currentEmptiedBottles>=numExchange){
            currentExtraNumberBottlesToDrink++;
            currentEmptiedBottles-=numExchange;
        }
        recentEmptiedBottles+=currentEmptiedBottles+currentExtraNumberBottlesToDrink;
        maxNumberBottlesToDrink+=currentExtraNumberBottlesToDrink;
        currentExtraNumberBottlesToDrink=0;
        currentEmptiedBottles=recentEmptiedBottles;
    }
    return maxNumberBottlesToDrink;
};