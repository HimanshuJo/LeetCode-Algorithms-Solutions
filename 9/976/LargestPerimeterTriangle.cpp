/*
https://leetcode.com/problems/largest-perimeter-triangle/description/?envType=daily-question&envId=2025-09-28
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int sz=nums.size(), res=INT_MIN;
        sort(nums.begin(), nums.end(), greater<>());
        for(int i=0; i<sz-2; ++i){
            int firstSide=nums[i], secSide=nums[i+1], thirdSide=nums[i+2];
            if(secSide+thirdSide>firstSide) return firstSide+secSide+thirdSide;
        }
        return 0;
    }
};