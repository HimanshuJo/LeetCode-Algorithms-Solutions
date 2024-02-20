/*
https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15
*/

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz=nums.size();
        for(int i=sz-1; i>=0; --i){
            long long curval=nums[i], cursm=0, count=0;
            for(int j=0; j<i; ++j){
                cursm+=nums[j];
                count++;
            }
            if(cursm>curval&&count>=2) return cursm+curval;
        }
        return -1;
    }
};