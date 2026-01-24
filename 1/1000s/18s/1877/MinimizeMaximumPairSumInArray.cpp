/*
https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/?envType=daily-question&envId=2026-01-24
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<int>maxes, mins;
        sort(nums.begin(), nums.end());
        int sz=nums.size();
        for(int i=0; i<sz/2; ++i){
            mins.push_back(nums[i]);
        }
        for(int i=sz-1; i>=sz/2; --i){
            maxes.push_back(nums[i]);
        }
        vector<pair<int, int>>pairs;
        for(int i=0; i<sz/2; ++i){
            pairs.push_back({maxes[i], mins[i]});
        }
        int res=INT_MIN, curmax=INT_MIN;
        for(int i=0; i<pairs.size(); ++i){
            curmax=max(curmax, pairs[i].first+pairs[i].second);
            res=max(res, curmax);
        }
        return res;
    }
};

// ------- ####### -------

class Solution_2 {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz=nums.size(), res=INT_MIN, curmax=INT_MIN;
        for(int i=0; i<sz/2; ++i){
            curmax=max(curmax, nums[i]+nums[sz-1-i]);
            res=max(res, curmax);
        }
        return res;
    }
};