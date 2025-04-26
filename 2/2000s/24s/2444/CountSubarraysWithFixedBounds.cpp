/*
https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2025-04-26
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int sz=nums.size(), lastMinIdx=-1, lastMaxIdx=-1, lastBadIdx=-1;
        long long res=0;
        for(int i=0; i<sz; ++i){
            if(nums[i]<minK||nums[i]>maxK){
                lastBadIdx=i;
            }
            if(nums[i]==minK){
                lastMinIdx=i;
            }
            if(nums[i]==maxK){
                lastMaxIdx=i;
            }
            int curValidIdx=min(lastMinIdx, lastMaxIdx);
            if(curValidIdx>lastBadIdx){
                res+=(curValidIdx-lastBadIdx);
            }   
        }
        return res;
    }
};