/*
https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/?envType=daily-question&envId=2025-06-19
*/

class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int lengthOfNums=nums.length, resultantMinSubSeq=0, prevMin=nums[0];
        for(int i=0; i<lengthOfNums; ++i){
            if(nums[i]-prevMin>k){
                resultantMinSubSeq++;
                prevMin=nums[i];
            }
        }
        return resultantMinSubSeq+1;
    }
}