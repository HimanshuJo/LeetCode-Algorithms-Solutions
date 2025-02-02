/*
https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09
*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        for(auto &vals: nums1){
            mp[vals]++;
        }
        for(auto &vals: nums2){
            if(mp.find(vals)!=mp.end()) return vals;
        }
        return -1;
    }
};