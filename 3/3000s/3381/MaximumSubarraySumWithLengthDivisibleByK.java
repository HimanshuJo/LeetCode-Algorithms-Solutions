/*
https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/?envType=daily-question&envId=2025-11-27
*/

class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        int lengthOfNums=nums.length;
        long resultantMaxSum=Long.MIN_VALUE;
        long[] prefixSum=new long[lengthOfNums+1];
        for(int i=0; i<lengthOfNums; ++i){
            prefixSum[i]=0;
        }
        for(int i=0; i<lengthOfNums; ++i){
            prefixSum[i+1]=prefixSum[i]+nums[i];
        }
        long[] prefixMin=new long[k+1];
        for(int i=0; i<k; ++i){
            prefixMin[i]=Long.MAX_VALUE;
        }
        for(int i=0; i<=lengthOfNums; ++i){
            int rem=i%k;
            if(prefixMin[rem]!=Long.MAX_VALUE){
                resultantMaxSum=Math.max(resultantMaxSum, prefixSum[i]-prefixMin[rem]);
            }
            prefixMin[rem]=Math.min(prefixMin[rem], prefixSum[i]);
        }
        return resultantMaxSum;
    }
}