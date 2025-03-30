/*
https://leetcode.com/problems/house-robber-iv/description/?envType=daily-question&envId=2025-03-15
*/

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int sz=nums.size(), minReward=INT_MAX, maxReward=INT_MIN;
        for(int i=0; i<sz; ++i){
            minReward=min(minReward, nums[i]);
            maxReward=max(maxReward, nums[i]);
        }
        while(minReward<=maxReward){
            int midReward=minReward+(maxReward-minReward)/2, numThefts=0;
            for(int index=0; index<sz; ++index){
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
        return minReward;
    }
};