/*
https://leetcode.com/problems/longest-balanced-subarray-i/?envType=daily-question&envId=2026-02-10
*/

class Solution {
    public int longestBalanced(int[] nums) {
        int lengthOfNums=nums.length, resultantMaxLength=0;
        for(int i=0; i<lengthOfNums; ++i){
            int currentEvenCount=0, currentOddCount=0;
            HashSet<Integer>seenNumbers=new HashSet<>();
            for(int j=i; j<lengthOfNums; ++j){
                if(!seenNumbers.contains(nums[j])){
                    if(nums[j]%2!=0){
                        currentOddCount++;
                    } else currentEvenCount++;
                }
                seenNumbers.add(nums[j]);
                if(currentEvenCount==currentOddCount){
                    resultantMaxLength=Math.max(resultantMaxLength, j-i+1);
                }
            }
        }
        return resultantMaxLength;
    }
}