/*
https://leetcode.com/problems/zero-array-transformation-ii/description/?envType=daily-question&envId=2025-03-13
*/

class Solution {

    public static boolean canMakeZeroArray(int[] nums, int[][] queries, int k){
        int numsLength=nums.length, queriesLength=queries.length;
        int[] diffSumArray=new int[numsLength+1];
        for(int i=0; i<numsLength+1; ++i){
            diffSumArray[i]=0;
        }
        for(int i=0; i<k; ++i){
            int curLeftBound=queries[i][0], curRightBound=queries[i][1], curVal=queries[i][2];
            diffSumArray[curLeftBound]+=curVal;
            diffSumArray[curRightBound+1]-=curVal;
        }
        int sum=0;
        for(int i=0; i<numsLength; ++i){
            sum+=diffSumArray[i];
            if(sum<nums[i]) return false;
        }
        return true;
    }

    public static int binarySearch(int[] nums, int[][] queries){
        int left=0, right=queries.length;
        if(!canMakeZeroArray(nums, queries, right)) return -1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canMakeZeroArray(nums, queries, mid)){
                right=mid-1;
            } else left=mid+1;
        }
        return left;
    }

    public int minZeroArray(int[] nums, int[][] queries) {
        return binarySearch(nums, queries);
    }
}
