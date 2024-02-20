/*
https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz=nums.size();
        for(int i=0; i<=sz; ++i){
            auto itr=find(nums.begin(), nums.end(), i);
            if(itr==nums.end()) return i;
        }
        return -1;
    }
};