/*
https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02
*/

public class Solution {

    public bool customSearch(int[] nums, int val){
        int left=0, right=nums.Length-1;
        while(left<=right){
            if(nums[left++]==-val) return true;
            else if(nums[right--]==-val) return true;
        }
        return false;
    }

    public int FindMaxK(int[] nums) {
        Array.Sort(nums);
        int sz=nums.Length;
        for(int i=sz-1; i>=0; --i){
            int curr=nums[i];
            if(curr>=0){
                bool flag=customSearch(nums, curr);
                if(flag==true) return curr;
            }
        }
        return -1;
    }
}