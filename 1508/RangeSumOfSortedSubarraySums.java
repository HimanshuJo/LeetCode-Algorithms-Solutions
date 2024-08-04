/*
https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/?envType=daily-question&envId=2024-08-04s
*/

class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        ArrayList<Long>allSubArraySums=new ArrayList<>();
        int lengthOfNums=nums.length, modulus=1000000000+7;
        long resultantSum=0;
        for(int i=0; i<lengthOfNums; ++i){
            long currentSubarraySum=0;
            for(int j=i; j<lengthOfNums; ++j){
                currentSubarraySum+=nums[j];
                currentSubarraySum%=modulus;
                allSubArraySums.add(currentSubarraySum);
            }
        }
        Collections.sort(allSubArraySums);
        for(int i=left-1; i<right; ++i){
            resultantSum+=allSubArraySums.get(i);
            resultantSum%=modulus;
        }
        return (int)resultantSum;
    }
}