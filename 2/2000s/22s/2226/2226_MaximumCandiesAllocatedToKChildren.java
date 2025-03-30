/*
https://leetcode.com/problems/maximum-candies-allocated-to-k-children/?envType=daily-question&envId=2025-03-14
*/

class Solution {

    public static boolean isValidSplit(int[] candies, long k, int currentSplitVal){
        int candiesLength=candies.length;
        long currentCandiesAllocated=0, currentSplits=0;
        for(int i=0; i<candiesLength; ++i){
            if(candies[i]<currentSplitVal) continue;
            currentCandiesAllocated+=candies[i];
            currentSplits+=candies[i]/currentSplitVal;
        }
        return currentCandiesAllocated>=k&&currentSplits>=k;
    }

    public static int binarySearch(int[] candies, long k){
        Arrays.sort(candies);
        int left=1, right=candies[candies.length-1], resultantMaxCandies=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValidSplit(candies, k, mid)){
                resultantMaxCandies=mid;
                left=mid+1;
            } else{
                right=mid-1;
            }
        }
        return resultantMaxCandies;
    }

    public int maximumCandies(int[] candies, long k) {
        return binarySearch(candies, k);
    }
}
