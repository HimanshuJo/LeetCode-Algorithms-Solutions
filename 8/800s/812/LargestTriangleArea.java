/*
https://leetcode.com/problems/largest-triangle-area/description/?envType=daily-question&envId=2025-09-27
*/

class Solution {
    public double largestTriangleArea(int[][] points) {
        int lengthOfPoints=points.length;
        double resultantMaxArea=0.0;
        for(int i=0; i<lengthOfPoints; ++i){
            for(int j=i+1; j<lengthOfPoints; ++j){
                for(int k=j+1; k<lengthOfPoints; ++k){
                    double firstCordX=points[i][0], firstCordY=points[i][1];
                    double secCordX=points[j][0], secCordY=points[j][1];
                    double thrdCordX=points[k][0], thrdCordY=points[k][1];
                    double currArea=0.5*Math.abs(firstCordX*(secCordY-thrdCordY)+secCordX*(thrdCordY-firstCordY)+thrdCordX*(firstCordY-secCordY));
                    resultantMaxArea=Math.max(resultantMaxArea, currArea);
                }
            }
        }
        return resultantMaxArea;
    }
}