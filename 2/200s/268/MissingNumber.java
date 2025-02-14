/*
https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20
*/

class Solution {

    public boolean binarySearch(int[] nums, int val){
        int left=0, right=nums.length-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==val) return true;
            else if(nums[mid]>val){
                right=mid-1;
            } else left=mid+1;
        }
        return false;
    }

    public boolean find(int[] nums, int val){
        return binarySearch(nums, val);
    }

    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        int sz=nums.length;
        for(int i=0; i<=sz; ++i){
            boolean flag=find(nums, i);
            if(!flag) return i;
        }
        return -1;
    }
}