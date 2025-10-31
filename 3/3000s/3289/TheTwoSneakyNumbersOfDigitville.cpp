/*
https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/?envType=daily-question&envId=2025-10-31
*/

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>res;
        map<int, int>mp;
        for(auto &vals: nums){
            mp[vals]++;
        }
        for(auto &entries: mp){
            if(entries.second>=2) res.push_back(entries.first);
        }
        return res;
    }
};