/*
https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20
*/

public class Solution {

    public bool binarySearch(int[] nums, int val){
        int left=0, right=nums.Length-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==val) return true;
            else if(nums[mid]>val){
                right=mid-1;
            } else left=mid+1;
        }
        return false;
    }

    public bool find(int[] nums, int val){
        return binarySearch(nums, val);
    }

    public int MissingNumber(int[] nums) {
        Array.Sort(nums);
        int sz=nums.Length;
        for(int i=0; i<=sz; ++i){
            bool flag=find(nums, i);
            if(!flag) return i;
        }
        return -1;
    }
}