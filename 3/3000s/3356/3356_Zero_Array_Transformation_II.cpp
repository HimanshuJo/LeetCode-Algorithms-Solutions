/*
https://leetcode.com/problems/zero-array-transformation-ii/description/?envType=daily-question&envId=2025-03-13
*/

class Solution {
public:

    bool canSumBeZero(vector<int>&nums, vector<vector<int>>&queries, int k){
        int sz1=nums.size(), sz2=queries.size(), sum=0;
        vector<int>diffSum(sz1+1, 0);
        for(int i=0; i<k; ++i){
            int curl=queries[i][0], curr=queries[i][1], curval=queries[i][2];
            diffSum[curl]+=curval, diffSum[curr+1]-=curval;
        }
        for(int i=0; i<sz1; ++i){
            sum+=diffSum[i];
            if(sum<nums[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left=0, right=queries.size();
        if(!canSumBeZero(nums, queries, queries.size())) return -1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canSumBeZero(nums, queries, mid)){
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return left;
    }
};
