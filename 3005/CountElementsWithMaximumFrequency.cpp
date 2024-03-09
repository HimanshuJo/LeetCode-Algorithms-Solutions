/*
https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2024-03-08
*/

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>mp1;
        map<int, vector<int>, greater<>>mp2;
        for(auto &vals: nums){
            mp1[vals]++;
        }
        for(auto &entries: mp1){
            mp2[entries.second].push_back(entries.first);
        }
        auto itr=mp2.begin();
        return itr->first*(itr->second).size();
    }
};