/*
https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-03-10
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        set<int>stres;
        unordered_map<int, int>mp;
        for(auto &vals: nums1){
            mp[vals]++;
        }
        for(auto &vals: nums2){
            if(mp.find(vals)!=mp.end()){
                stres.insert(vals);
            }
        }
        for(auto &vals: stres){
            res.push_back(vals);
        }
        return res;
    }
};