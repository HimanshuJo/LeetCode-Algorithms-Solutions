/*
https://leetcode.com/problems/rabbits-in-forest/description/?envType=daily-question&envId=2025-04-20
*/

/**
 * @param {number[]} answers
 * @return {number}
 */
var numRabbits = function(answers) {
    let lengthOfAnswers=answers.length, resultantMinNumRabbits=0;
    let frequencyMap=new Map();
    for(let i=0; i<lengthOfAnswers; ++i){
        if(frequencyMap.has(answers[i])){
            frequencyMap.set(answers[i], frequencyMap.get(answers[i])+1);
        } else frequencyMap.set(answers[i], 1);
    }
    for(const [key, vals] of frequencyMap.entries()){
        let currentPossGroupSize=key+1, numRabbitsSayingCurrCount=vals;
        let totalPossRabsForCurrentGroup=Math.floor((numRabbitsSayingCurrCount+currentPossGroupSize-1)/currentPossGroupSize);
        resultantMinNumRabbits+=(currentPossGroupSize*totalPossRabsForCurrentGroup);
    }
    return resultantMinNumRabbits;
};