/*
https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=daily-question&envId=2025-06-29
*/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sz=nums.size(), res=0, mod=1e9+7;
        vector<int>pow2(sz, 0);
        pow2[0]=1;
        for(int i=1; i<sz; ++i){
            pow2[i]=pow2[i-1]*2;
            pow2[i]%=mod;
        }
        int left=0, right=sz-1;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                res+=pow2[right-left];
                res%=mod;
                left++;
            } else right--;
        }
        return res;
    }
};