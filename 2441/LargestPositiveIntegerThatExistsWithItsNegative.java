/*
https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02
*/

class Solution {

    public boolean customSearch(int[] nums, int val){
        int left=0, right=nums.length-1;
        while(left<=right){
            if(nums[left++]==-val) return true;
            else if(nums[right--]==-val) return true;
        }
        return false;
    }

    public int findMaxK(int[] nums) {
        Arrays.sort(nums);
        int sz=nums.length;
        for(int i=sz-1; i>=0; --i){
            int curr=nums[i];
            if(curr>=0){
                boolean flag=customSearch(nums, curr);
                if(flag) return curr;
            }
        }
        return -1;
    }
}