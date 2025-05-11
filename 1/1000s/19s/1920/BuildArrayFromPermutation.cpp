/*
https://leetcode.com/problems/build-array-from-permutation/description/?envType=daily-question&envId=2025-05-06
*/

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int sz=nums.size();
        vector<int>res(sz, 0);
        for(int i=0; i<sz; ++i){
            res[i]=nums[nums[i]];
        }
        return res;
    }
};