/*
https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02
*/

class Solution {
    public int[] sortedSquares(int[] nums) {
        int sz=nums.length;
        int[] res=new int[sz];
        for(int i=0; i<sz; ++i){
            res[i]=nums[i]*nums[i];
        }
        Arrays.sort(res);
        return res;
    }
}