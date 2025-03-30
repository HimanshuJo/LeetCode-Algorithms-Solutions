/*
https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/?envType=daily-question&envId=2025-03-12
*/

// TC: O(N), SC: O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int sz=nums.size(), countPos=0, countNegs=0, res=0;
        for(int i=0; i<sz; ++i){
            if(nums[i]==0) continue;
            else if(nums[i]>=1) countPos++;
            else countNegs++;
            res=max(countPos, countNegs);
        }
        return res;
    }
};
