/*
https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/?envType=daily-question&envId=2025-11-29
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cursm=0;
        for(auto &vals: nums){
            cursm+=vals;
        }
        if(cursm%k==0) return 0;
        int sz=nums.size(), res=0;
        for(int i=sz-1; i>=0; --i){
            while(true){
                if(nums[i]==0) break;
                nums[i]--;
                cursm--;
                res++;
                if(cursm%k==0) return res;
            }
        }
        return res;
    }
};