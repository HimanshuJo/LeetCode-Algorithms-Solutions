/*
https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2024-03-24
*/

class Solution {
    public int findDuplicate(int[] nums) {
        Arrays.sort(nums);
        int sz=nums.length, prev=-1;
        for(int i=0; i<sz; ++i){
            if(nums[i]==prev) return nums[i];
            prev=nums[i];
        }
        return -1;
    }
}