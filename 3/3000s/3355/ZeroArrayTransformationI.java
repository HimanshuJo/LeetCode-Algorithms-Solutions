/*
https://leetcode.com/problems/zero-array-transformation-i/description/?envType=daily-question&envId=2025-05-20
*/

class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int lengthOfNums=nums.length, lengthOfQueries=queries.length;
        ArrayList<Integer>differenceVector=new ArrayList<>();
        for(int i=0; i<=lengthOfNums; ++i){
            differenceVector.add(0);
        }
        for(int i=0; i<lengthOfQueries; ++i){
            int left=queries[i][0], right=queries[i][1];
            differenceVector.set(left, differenceVector.get(left)+1);
            differenceVector.set(right+1, differenceVector.get(right+1)-1);
        }
        ArrayList<Integer>allAvailableOperations=new ArrayList<>();
        int currentOperation=0;
        for(int diff: differenceVector){
            currentOperation+=diff;
            allAvailableOperations.add(currentOperation);
        }
        for(int i=0; i<lengthOfNums; ++i){
            if(allAvailableOperations.get(i)<nums[i]) return false;
        }
        return true;
    }
}