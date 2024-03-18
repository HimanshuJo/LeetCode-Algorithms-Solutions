/*
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/?envType=daily-question&envId=2024-03-18
*/

class CustomComparator implements Comparator<int[]>{
    @Override
    public int compare(int[] arr1, int[] arr2){
        return Integer.compare(arr1[1], arr2[1]);
    }
}

class Solution {
    public int findMinArrowShots(int[][] points) {
        if(points.length==0) return 0;
        Arrays.sort(points, new CustomComparator());
        int arrows=1, curend=points[0][1], sz=points.length;
        for(int i=1; i<sz; ++i){
            if(points[i][0]>curend){
                arrows++;
                curend=points[i][1];
            }
        }
        return arrows;
    }
}