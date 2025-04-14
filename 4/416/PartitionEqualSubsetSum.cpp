/*
https://leetcode.com/problems/partition-equal-subset-sum/description/?envType=daily-question&envId=2025-04-07
*/

class Solution {
public:

    bool dfs(vector<int>&nums, const int sz, int curidx, int cursm, vector<vector<int>>&memo){
        if(cursm==0) return true;
        if(curidx>=sz||cursm<0) return false;
        if(memo[curidx][cursm]!=-1) return memo[curidx][cursm];
        bool canPk=dfs(nums, sz, curidx+1, cursm-nums[curidx], memo);
        bool canNtpk=dfs(nums, sz, curidx+1, cursm, memo);
        return memo[curidx][cursm]=canPk||canNtpk;
    }

    bool canPartition(vector<int>& nums) {
        int sz=nums.size(), sm=0;
        for(int i=0; i<sz; ++i){
            sm+=nums[i];
        }
        if(sm%2!=0) return false;
        int curidx=0, togt=sm/2;
        vector<vector<int>>memo(sz, vector<int>(togt+1, -1));
        return dfs(nums, sz, curidx, togt, memo);
    }
};