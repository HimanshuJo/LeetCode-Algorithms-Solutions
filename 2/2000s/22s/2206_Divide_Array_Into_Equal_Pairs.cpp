/*
https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=daily-question&envId=2025-03-17
*/

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz=nums.size(), nmPairs=sz/2, subPrSz=sz/nmPairs, idx=0;
        pair<int, int>prev;
        while(true){
            if(idx>=sz) break;
            if(prev.first==subPrSz){
                prev.first=0, prev.second=0;
                prev.first++;
                prev.second=nums[idx];
                idx++;
            } else{
                if(prev.first>=1){
                    int tocheck=nums[idx];
                    if(tocheck!=prev.second) return false;
                    prev.first++;
                    idx++;
                } else{
                    prev.first++;
                    prev.second=nums[idx];
                    idx++;
                }
            }
        }
        return true;
    }
};
