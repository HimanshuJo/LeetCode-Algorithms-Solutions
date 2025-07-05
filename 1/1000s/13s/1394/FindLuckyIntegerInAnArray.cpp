/*
https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=daily-question&envId=2025-07-05
*/

class Solution {
public:

    bool isLucky(vector<int>&vec, int val){
        int freq=0;
        for(auto &vals: vec){
            if(vals==val){
                freq++;
            }
        }
        return freq==val;
    }

    int findLucky(vector<int>& arr) {
        int sz=arr.size();
        set<int>all;
        for(int i=0; i<sz; ++i){
            if(isLucky(arr, arr[i])){
                all.insert(arr[i]);
            }
        }
        if(all.size()==0) return -1;
        auto itr=all.rbegin();
        return *itr;
    }
};