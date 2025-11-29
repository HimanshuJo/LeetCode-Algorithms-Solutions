/*
https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/?envType=daily-question&envId=2025-11-29
*/

class Solution {
    public int minOperations(int[] nums, int k) {
        Arrays.sort(nums);
        int currentSum=0;
        for(int num: nums){
            currentSum+=num;
        }
        if(currentSum%k==0) return 0;
        int lengthOfNums=nums.length, resultantOperations=0;
        for(int i=lengthOfNums-1; i>=0; --i){
            while(true){
                if(nums[i]==0) break;
                nums[i]--;
                currentSum--;
                resultantOperations++;
                if(currentSum%k==0) return resultantOperations;
            }
        }
        return resultantOperations;
    }
}