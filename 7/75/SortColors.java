/*
https://leetcode.com/problems/sort-colors/description/?envType=daily-question&envId=2025-05-17
*/

class Solution {
    public void sortColors(int[] nums) {
        int lengthOfNums=nums.length, countRed=0, countWhite=0, countBlue=0, beginIndex=0;
        for(int i=0; i<lengthOfNums; ++i){
            if(nums[i]==0) countRed++;
            else if(nums[i]==1) countWhite++;
            else countBlue++;
        }
        while(true){
            if(beginIndex>=lengthOfNums) break;
            while(countRed-- >0){
                nums[beginIndex++]=0;
                if(beginIndex>=lengthOfNums) break;
            }
            while(countWhite-- >0){
                nums[beginIndex++]=1;
                if(beginIndex>=lengthOfNums) break;
            }
            while(countBlue-- >0){
                nums[beginIndex++]=2;
                if(beginIndex>=lengthOfNums) break;
            }
        }
    }
}