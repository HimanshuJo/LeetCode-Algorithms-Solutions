/*
https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/description/?envType=daily-question&envId=2025-04-08
*/

class Solution {

    public static boolean isValidArray(int[] nums){
        int lengthOfNums=nums.length;
        if(lengthOfNums==0) return true;
        HashMap<Integer, Integer>numsItemsMap=new HashMap<>();
        for(int i=0; i<lengthOfNums; ++i){
            if(numsItemsMap.containsKey(nums[i])){
                return false;
            }
            numsItemsMap.put(nums[i], nums[i]);
        }
        return true;
    }

    public int minimumOperations(int[] nums) {
        int resultantMinOperations=0;
        while(true){
            if(isValidArray(nums)) break;
            if(nums.length<3){
                resultantMinOperations++;
                break;
            } else{
                int[] tempNums=new int[nums.length-3];
                for(int i=3; i<nums.length; ++i){
                    tempNums[i-3]=nums[i];
                }
                resultantMinOperations++;
                nums=tempNums;
            }
        }
        return resultantMinOperations;
    }
}
