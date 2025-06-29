/*
https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=daily-question&envId=2025-06-29
*/

class Solution {
    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        int lengthOfNums=nums.length, modulo=1000000000+7;
        int[] powOfTwo=new int[lengthOfNums];
        powOfTwo[0]=1;
        for(int i=1; i<lengthOfNums; ++i){
            powOfTwo[i]=powOfTwo[i-1]*2;
            powOfTwo[i]%=modulo;
        }
        int left=0, right=lengthOfNums-1, resultantSubsequences=0;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                resultantSubsequences+=powOfTwo[right-left];
                resultantSubsequences%=modulo;
                left++;
            } else right--;
        }
        return resultantSubsequences;
    }
}