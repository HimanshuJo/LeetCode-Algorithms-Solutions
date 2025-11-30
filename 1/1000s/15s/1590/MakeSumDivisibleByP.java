/*
https://leetcode.com/problems/make-sum-divisible-by-p/?envType=daily-question&envId=2025-11-30
*/

class Solution {
    public int minSubarray(int[] nums, int p) {
        int lengthOfNums=nums.length, resultantMinLength=lengthOfNums;
        long totalSum=0L;
        for(int num: nums){
            totalSum+=num;
        }
        long target=totalSum%p;
        if(target==0) return 0;
        HashMap<Long, Integer>prefixSumIndexMapping=new HashMap<>();
        prefixSumIndexMapping.put(0L, -1);
        long prefixSum=0;
        for(int i=0; i<lengthOfNums; ++i){
            prefixSum=(prefixSum+nums[i])%p;
            long needed=(prefixSum-target+p)%p;
            if(prefixSumIndexMapping.containsKey(needed)){
                resultantMinLength=Math.min(resultantMinLength, i-prefixSumIndexMapping.get(needed));
            }
            prefixSumIndexMapping.put(prefixSum, i);
        }
        return resultantMinLength==lengthOfNums?-1:resultantMinLength;
    }
}