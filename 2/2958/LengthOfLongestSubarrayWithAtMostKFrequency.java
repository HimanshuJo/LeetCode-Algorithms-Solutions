/*
https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28
*/

class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int sz=nums.length, left=-1, right=0, res=0;
        HashMap<Integer, Integer>mp=new HashMap<>();
        for(; right<sz; ++right){
            if(mp.containsKey(nums[right])){
                mp.put(nums[right], mp.get(nums[right])+1);
                while(mp.get(nums[right])>k){
                    left++;
                    mp.put(nums[left], mp.get(nums[left])-1);
                }
            } else mp.put(nums[right], 1);
            res=Math.max(res, right-left);
        }
        return res;
    }
}