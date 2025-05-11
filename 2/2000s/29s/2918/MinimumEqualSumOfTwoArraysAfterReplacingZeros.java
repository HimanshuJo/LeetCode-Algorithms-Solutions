/*
https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/?envType=daily-question&envId=2025-05-10
*/

class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long nums1Sum=0, nums2Sum=0;
        int countZerosNums1=0, countZerosNums2=0;
        for(int num: nums1){
            if(num==0) countZerosNums1++;
            nums1Sum+=num;
        }
        for(int num: nums2){
            if(num==0) countZerosNums2++;
            nums2Sum+=num;
        }
        if(nums1Sum==nums2Sum&&countZerosNums1!=0&&countZerosNums2!=0)
            return nums1Sum+=Math.max(countZerosNums1, countZerosNums2);
        if((nums2Sum+countZerosNums2)>(nums1Sum+countZerosNums1)){
            while(countZerosNums2-- >0){
                nums2Sum++;
            }
            if(countZerosNums1==0&&nums1Sum!=nums2Sum) return -1;
            else if(countZerosNums1==0&&nums1Sum==nums2Sum) return nums2Sum;
            while(countZerosNums1!=1){
                nums1Sum++;
                countZerosNums1--;
            }
            if(nums1Sum>=nums2Sum) return -1;
            return nums2Sum;
        }
        while(countZerosNums1-- >0){
            nums1Sum++;
        }
        if(countZerosNums2==0&&nums1Sum!=nums2Sum) return -1;
        else if(countZerosNums2==0&&nums1Sum==nums2Sum) return nums2Sum;
        while(countZerosNums2!=1){
            nums2Sum++;
            countZerosNums2--;
        }
        if(nums2Sum>=nums1Sum) return -1;
        return nums1Sum;
    }
}