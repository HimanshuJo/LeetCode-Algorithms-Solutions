/*
https://leetcode.com/problems/largest-divisible-subset/?envType=daily-question&envId=2025-04-06
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz=nums.size();
        vector<int>dp(sz, 1);
        vector<int>prev(sz, -1);
        int maxIdx=0;
        for(int i=1; i<sz; ++i){
            for(int j=0; j<i; ++j){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                }
            }
            if(dp[i]>dp[maxIdx]){
                maxIdx=i;
            }
        }
        vector<int>res;
        while(maxIdx!=-1){
            res.push_back(nums[maxIdx]);
            maxIdx=prev[maxIdx];
        }
        return res;
    }
};