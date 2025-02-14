/*
https://leetcode.com/problems/find-missing-observations/?envType=daily-question&envId=2024-09-05
*/

class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int lengthOfRolls=rolls.length, currentSum=0;
        for(int i=0; i<lengthOfRolls; ++i){
            currentSum+=rolls[i];
        }
        int remainingSumToFind=(mean*(lengthOfRolls+n))-(currentSum);
        if(remainingSumToFind>6*n||remainingSumToFind<n) return new int[0];
        int contributionOfRemainingSumInParts=remainingSumToFind/n, remainingCountToAddAfterContribution=remainingSumToFind%n;
        int[] resultantArrayOfMissingNumbers=new int[n];
        for(int i=0; i<n; ++i){
            resultantArrayOfMissingNumbers[i]=contributionOfRemainingSumInParts;
        }
        for(int i=0; i<remainingCountToAddAfterContribution; ++i){
            resultantArrayOfMissingNumbers[i]++;
        }
        return resultantArrayOfMissingNumbers;
    }
}