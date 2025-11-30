/*
https://leetcode.com/problems/make-sum-divisible-by-p/?envType=daily-question&envId=2025-11-30
*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sz=nums.size(), res=sz;
        long long totalSum=0;
        for(auto &vals: nums){
            totalSum+=vals;
        }
        int target=totalSum%p;
        if(target==0) return 0;
        unordered_map<int, int>mp;
        mp[0]=-1;
        long long prefixSum=0;
        for(int i=0; i<sz; ++i){
            prefixSum=(prefixSum+nums[i])%p;
            int needed=(prefixSum-target+p)%p;
            if(mp.count(needed)){
                res=min(res, i-mp[needed]);
            }
            mp[prefixSum]=i;
        }
        return res==sz?-1:res;
    }
};