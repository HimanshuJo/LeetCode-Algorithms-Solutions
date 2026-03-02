/*
https://leetcode.com/problems/longest-balanced-subarray-i/?envType=daily-question&envId=2026-02-10
*/

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int sz=nums.size(), res=0;
        for(int i=0; i<sz; ++i){
            int curEvenCount=0, curOddCount=0;
            set<int>seen;
            for(int j=i; j<sz; ++j){
                if(seen.find(nums[j])==seen.end()){
                    if(nums[j]&1){
                        curOddCount++;
                    } else curEvenCount++;
                    seen.insert(nums[j]);
                }
                if(curEvenCount==curOddCount){
                    res=max(res, j-i+1);
                }
            }
        }
        return res;
    }
};