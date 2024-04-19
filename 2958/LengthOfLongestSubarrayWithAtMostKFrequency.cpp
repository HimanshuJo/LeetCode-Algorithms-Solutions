/*
https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28
*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int sz=nums.size(), left=-1, right=0, res=0;
        unordered_map<int, int>mp;
        for(; right<sz; ++right){
            mp[nums[right]]++;
            while(mp[nums[right]]>k){
                left++;
                mp[nums[left]]--;
            }
            res=max(res, right-left);
        }
        return res;
    }
};