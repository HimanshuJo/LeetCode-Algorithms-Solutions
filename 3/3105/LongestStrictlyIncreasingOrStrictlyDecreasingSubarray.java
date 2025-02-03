/*
https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/?envType=daily-question&envId=2025-02-03
*/

class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int lengthOfNums=nums.length, resultantLength=Integer.MIN_VALUE;
        for(int i=0; i<lengthOfNums; ++i){
            int currentNums=nums[i], currentLength=1;
            if(i+1<=lengthOfNums-1){
                for(int j=i+1; j<lengthOfNums; ++j){
                    if(nums[j]>currentNums){
                        currentLength++;
                        currentNums=nums[j];
                    } else break;
                }
            }
            resultantLength=Math.max(resultantLength, currentLength);
        }
        for(int i=0; i<lengthOfNums; ++i){
            int currentNums=nums[i], currentLength=1;
            if(i+1<=lengthOfNums-1){
                for(int j=i+1; j<lengthOfNums; ++j){
                    if(nums[j]<currentNums){
                        currentLength++;
                        currentNums=nums[j];
                    } else break;
                }
            }
            resultantLength=Math.max(resultantLength, currentLength);
        }
        return resultantLength;
    }
}