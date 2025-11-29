/*
https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/?envType=daily-question&envId=2025-11-17
*/

class Solution {
public:

    bool isValid(int firstIndex, int secIndex, int k){
        return ((abs(firstIndex-secIndex))-1>=k);
    }

    bool kLengthApart(vector<int>& nums, int k) {
        if(k==0) return true;
        int sz=nums.size();
        vector<int>allIndices;
        for(int i=0; i<sz; ++i){
            if(nums[i]==1) allIndices.push_back(i);
        }
        for(auto &vals: allIndices){
            int curIdx=vals;
            for(auto &anthVals: allIndices){
                int secIdx=anthVals;
                if(curIdx!=secIdx){
                    if(!isValid(curIdx, secIdx, k)) return false;
                }
            }
        }
        return true;
    }
};