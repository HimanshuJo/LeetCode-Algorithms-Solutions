/*
https://leetcode.com/problems/xor-queries-of-a-subarray/description/?envType=daily-question&envId=2024-09-13
*/

class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] resultantArray=new int[queries.length];
        int beginIndex=0;
        for(int[] query: queries){
            int left=query[0], right=query[1], currentXOR=0;
            for(int i=left; i<=right; ++i){
                currentXOR^=arr[i];
            }
            resultantArray[beginIndex++]=currentXOR;
        }
        return resultantArray;
    }
}