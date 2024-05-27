/*
https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/submissions/1269613113/?envType=daily-question&envId=2024-05-27
*/

class Solution {

    public boolean checkNumbersInNumsGreaterThanEqualToCurrentNumber(int currentNumber, int[] nums){
        int lengthOfNums=nums.length, countOfNumbersGreaterThanEqualToCurrentNumber=0;
        for(int i=0; i<lengthOfNums; ++i){
            if(nums[i]>=currentNumber){
                countOfNumbersGreaterThanEqualToCurrentNumber++;
            }
        }
        if(countOfNumbersGreaterThanEqualToCurrentNumber==currentNumber) return true;
        return false;
    }

    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        int lengthOfNums=nums.length;
        int lastNumberToCheck=nums[lengthOfNums-1];
        for(int currentNumber=0; currentNumber<=lastNumberToCheck; ++currentNumber){
            if(checkNumbersInNumsGreaterThanEqualToCurrentNumber(currentNumber, nums)){
                return currentNumber;
            }
        }
        return -1;
    }
}