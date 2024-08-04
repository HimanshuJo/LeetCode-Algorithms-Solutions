/*
https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/?envType=daily-question&envId=2024-08-04s
*/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>allSums;
        int sz=nums.size(), mod=1e9+7;
        long long res=0;
        for(int i=0; i<sz; ++i){
            long long cursm=0;
            for(int j=i; j<sz; ++j){
                cursm+=nums[j];
                cursm%=mod;
                allSums.push_back(cursm);
            }
        }
        sort(allSums.begin(), allSums.end());
        for(int i=left-1; i<right; ++i){
            res+=allSums[i];
            res%=mod;
        }
        return res;
    }
};