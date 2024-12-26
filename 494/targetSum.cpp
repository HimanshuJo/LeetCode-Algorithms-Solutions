/*
https://leetcode.com/problems/target-sum/description/?envType=daily-question&envId=2024-12-26
*/

class Solution {
public:

    int dfs(vector<int>&nums, int target, int sz, int curidx, int cursum){
        if(curidx==sz){
            if(cursum==target) return 1;
            return 0;
        }
        int pkplus=0, pkminus=0;
        pkplus+=dfs(nums, target, sz, curidx+1, cursum+nums[curidx]);
        pkminus+=dfs(nums, target, sz, curidx+1, cursum+(nums[curidx]*-1));
        return pkplus+pkminus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sz=nums.size(), idx=0, cursum=0;
        return dfs(nums, target, sz, idx, cursum);
    }
};