/*
https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/?envType=daily-question&envId=2025-06-19
*/

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sz=nums.size(), res=0, prev=nums[0];
        for(int i=0; i<sz; ++i){
            if(nums[i]-prev>k){
                res++;
                prev=nums[i];
            }
        }
        return res+1;
    }
};