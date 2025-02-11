/*
https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23
*/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int>mp1;
        map<int, vector<int>>mp2;
        for(auto &vals: nums){
            mp1[vals]++;
        }
        for(auto &entries: mp1){
            mp2[entries.second].push_back(entries.first);
        }
        vector<int>res;
        for(auto &entries: mp2){
            if(entries.second.size()>=2){
                sort(entries.second.begin(), entries.second.end());
                int sz=entries.second.size();
                for(int i=sz-1; i>=0; --i){
                    for(int j=0; j<entries.first; ++j){
                        res.push_back(entries.second[i]);
                    }
                }
            } else{
                for(int j=0; j<entries.first; ++j){
                    res.push_back(entries.second.back());
                }
            }
        }
        return res;
    }
};