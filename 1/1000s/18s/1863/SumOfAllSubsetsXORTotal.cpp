/*
https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2024-05-20
*/

class Solution {
public:

    void dfs(vector<int>&nums, vector<vector<int>>&res, vector<int>&curr, int idx){
        if(curr.size()>=1) res.push_back(curr);
        for(int i=idx; i<nums.size(); ++i){
            curr.push_back(nums[i]);
            dfs(nums, res, curr, i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> findAllSubsets(vector<int>&nums){
        vector<vector<int>>res;
        vector<int>curr;
        dfs(nums, res, curr, 0);
        return res;
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>allSubs=findAllSubsets(nums);
        int sz=nums.size(), res=0;
        for(int i=0; i<allSubs.size(); ++i){
            int curxor=0;
            for(auto &vals: allSubs[i]){
                curxor^=vals;
            }
            res+=curxor;
        }
        return res;
    }
};