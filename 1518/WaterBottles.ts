/*
https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2024-07-07
*/

function numWaterBottles(numBottles: number, numExchange: number): number {
    let maxNumberBottlesToDrink:number=0, currentExtraNumberBottlesToDrink:number=0, currentEmptiedBottles:number=0;
    maxNumberBottlesToDrink+=numBottles, currentEmptiedBottles+=numBottles;
    while(true){
        if(currentEmptiedBottles<numExchange) break;
        let recentEmptiedBottles:number=0;
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