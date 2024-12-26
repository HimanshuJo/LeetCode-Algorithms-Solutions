/*
https://leetcode.com/problems/target-sum/description/?envType=daily-question&envId=2024-12-26
*/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

var depthFirstSearch_forArrays=function(nums, target, lengthOfNums, beginIndex, currentSum){
    if(beginIndex===lengthOfNums){
        if(currentSum===target) return 1;
        return 0;
    }
    let pickPlus=0, pickMinus=0;
    pickPlus+=depthFirstSearch_forArrays(nums, target, lengthOfNums, beginIndex+1, currentSum+nums[beginIndex]);
    pickMinus+=depthFirstSearch_forArrays(nums, target, lengthOfNums, beginIndex+1, currentSum+(nums[beginIndex]*-1));
    return pickPlus+pickMinus;
}

var findTargetSumWays = function(nums, target) {
    let lengthOfNums=nums.length, beginIndex=0, currentSum=0;
    return depthFirstSearch_forArrays(nums, target, lengthOfNums, beginIndex, currentSum);
};