/*
https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=daily-question&envId=2024-05-27
*/

class Solution {
public:

    bool isValid(int numToChk, vector<int>&nums){
        int count=0;
        for(auto &vals: nums){
            if(vals>=numToChk) count++;
        }
        return count==numToChk;
    }

    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int fnnum=nums.back();
        for(int i=0; i<=fnnum; ++i){
            if(isValid(i, nums)) return i;
        }
        return -1;
    }
};