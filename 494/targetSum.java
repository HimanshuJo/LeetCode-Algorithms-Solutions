/*
https://leetcode.com/problems/target-sum/description/?envType=daily-question&envId=2024-12-26
*/

class Solution {

    public int depthFirstSearch_forArrays(int[] nums, int target, int lengthOfNums, int currentIndex, int currentSum){
        if(currentIndex==lengthOfNums){
            if(currentSum==target) return 1;
            return 0;
        }
        int pickPlus=0, pickMinus=0;
        pickPlus+=depthFirstSearch_forArrays(nums, target, lengthOfNums, currentIndex+1, currentSum+nums[currentIndex]);
        pickMinus+=depthFirstSearch_forArrays(nums, target, lengthOfNums, currentIndex+1, currentSum+(nums[currentIndex]*-1));
        return pickPlus+pickMinus;
    }

    public int findTargetSumWays(int[] nums, int target) {
        int lengthOfNums=nums.length, beginIndex=0, currentSum=0;
        return depthFirstSearch_forArrays(nums, target, lengthOfNums, beginIndex, currentSum);
    }
}