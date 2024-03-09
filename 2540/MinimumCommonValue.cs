/*
https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09
*/

public class Solution {
    public int GetCommon(int[] nums1, int[] nums2) {
        Dictionary<int, int>dict=new Dictionary<int, int>();
        int sz1=nums1.Length, sz2=nums2.Length;
        for(int i=0; i<sz1; ++i){
            if(dict.ContainsKey(nums1[i])){
                dict[nums1[i]]+=1;
            } else dict.Add(nums1[i], 1);
        }
        for(int i=0; i<sz2; ++i){
            if(dict.ContainsKey(nums2[i])) return nums2[i];
        }
        return -1;
    }
}