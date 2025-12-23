/*
https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2025-12-23
*/

class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (a, b)->Integer.compare(a[0], b[0]));
        int lengthOfEvents=events.length, resultantMaxSum=Integer.MIN_VALUE;
        for(int i=0; i<lengthOfEvents; ++i){
            resultantMaxSum=Math.max(resultantMaxSum, events[i][2]);
        }
        int[] bestForEachIndex=new int[lengthOfEvents+1];
        for(int i=lengthOfEvents-1; i>=0; --i){
            bestForEachIndex[i]=Math.max(bestForEachIndex[i+1], events[i][2]);
        }
        for(int i=0; i<lengthOfEvents; ++i){
            int currentBegin=events[i][0], currentEnd=events[i][1], currentValue=events[i][2];
            int left=i+1, right=lengthOfEvents;
            while(left<right){
                int mid=left+(right-left)/2;
                if(events[mid][0]>currentEnd){
                    right=mid;
                } else left=mid+1;
            }
            resultantMaxSum=Math.max(resultantMaxSum, currentValue+bestForEachIndex[left]);
        }
        return resultantMaxSum;
    }
}