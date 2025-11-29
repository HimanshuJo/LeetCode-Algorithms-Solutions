/*
https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/?envType=daily-question&envId=2025-11-27
*/

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int sz=nums.size();
        long long res=LLONG_MIN;
        vector<long long>prefSum(sz+1, 0);
        for(int i=0; i<sz; ++i){
            prefSum[i+1]=nums[i]+prefSum[i];
        }
        vector<long long>prefMin(k+1, LLONG_MAX);
        for(int i=0; i<=sz; ++i){
            int r=i%k;
            if(prefMin[r]!=LLONG_MAX){
                res=max(res, prefSum[i]-prefMin[r]);
            }
            prefMin[r]=min(prefMin[r], prefSum[i]);
        }
        return res;
    }
};