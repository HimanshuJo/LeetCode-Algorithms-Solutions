/*
https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res;
        int sz=nums.size();
        for(int i=0; i<sz; ++i){
            res.push_back(nums[i]*nums[i]);
        }
        sort(res.begin(), res.end());
        return res;
    }
};