/*
https://leetcode.com/problems/house-robber-iv/description/?envType=daily-question&envId=2025-03-15
*/

class Solution {
    public int minCapability(int[] nums, int k) {
        int lengthOfNums=nums.length,
            minReward=Integer.MAX_VALUE, 
            maxReward=Integer.MIN_VALUE, 
            resultantMinCapability=Integer.MAX_VALUE;
        for(int i=0; i<lengthOfNums; ++i){
            minReward=Math.min(minReward, nums[i]);
            maxReward=Math.max(maxReward, nums[i]);
        }
        while(minReward<=maxReward){
            int midReward=minReward+(maxReward-minReward)/2, numThefts=0;
            for(int index=0; index<lengthOfNums; ++index){
                if(nums[index]<=midReward){
                    numThefts++;
                    index++;
                }
            }
            if(numThefts>=k){
                maxReward=midReward-1;
            } else{
                minReward=midReward+1;
            }
        }
        resultantMinCapability=Math.min(resultantMinCapability, minReward);
        return resultantMinCapability;
    }
}