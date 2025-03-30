/*
https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/?envType=daily-question&envId=2025-02-03
*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int sz=nums.size(), res=INT_MIN;
        for(int i=0; i<sz; ++i){
            int curnum=nums[i], curlength=1;
            if(i+1<=sz-1){
                for(int j=i+1; j<sz; ++j){
                    if(nums[j]>curnum){
                        curlength++;
                        curnum=nums[j];
                    } else break;
                }
            }
            res=max(res, curlength);
        }
        for(int i=0; i<sz; ++i){
            int curnum=nums[i], curlength=1;
            if(i+1<=sz-1){
                for(int j=i+1; j<sz; ++j){
                    if(nums[j]<curnum){
                        curlength++;
                        curnum=nums[j];
                    } else break;
                }
            }
            res=max(res, curlength);
        }
        return res;
    }
};