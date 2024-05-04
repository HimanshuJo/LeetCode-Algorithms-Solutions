/*
https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02
*/

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz=nums.size();
        for(int i=sz-1; i>=0; --i){
            int curr=nums[i];
            auto itr=find(nums.begin(), nums.end(), curr*-1);
            if(itr!=nums.end()) return curr;
        }
        return -1;
    }
};