/*
https://leetcode.com/problems/container-with-most-water/?envType=daily-question&envId=2025-10-04
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz=height.size(), res=INT_MIN;
        int left=0, right=sz-1;
        while(left<=right){
            int curAmount=min(height[left], height[right])*(right-left);
            res=max(res, curAmount);
            if(height[left]<=height[right]){
                left++;
            } else right--;
        }
        return res;
    }
};