/*
https://leetcode.com/problems/largest-perimeter-triangle/description/?envType=daily-question&envId=2025-09-28
*/

class Solution {
    public int largestPerimeter(int[] nums) {
        int lengthOfNums=nums.length;
        Arrays.sort(nums);
        for(int i=lengthOfNums-1; i>=2; --i){
            int firstSide=nums[i], secSide=nums[i-1], thirdSide=nums[i-2];
            if(secSide+thirdSide>firstSide){
                return firstSide+secSide+thirdSide;
            }
        }
        return 0;
    }
}