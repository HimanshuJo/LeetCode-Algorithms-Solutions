/*
https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15
*/

public class Solution {
    public long LargestPerimeter(int[] nums) {
        Array.Sort(nums);
        int sz=nums.Length;
        for(int i=sz-1; i>=2; --i){
            long curval=nums[i], cursm=0;
            for(int j=0; j<i; ++j){
                cursm+=nums[j];
            }
            if(cursm>curval) return cursm+curval;
        }
        return -1;
    }
}