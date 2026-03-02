/*
https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/?envType=daily-question&envId=2026-03-02
*/

class Solution {
    public int minSwaps(int[][] grid) {
        int lengthOfGrid=grid.length;
        int[] positions=new int[lengthOfGrid];
        for(int i=0; i<lengthOfGrid; ++i){
            positions[i]=-1;
        }
        for(int i=0; i<lengthOfGrid; ++i){
            for(int j=lengthOfGrid-1; j>=0; --j){
                if(grid[i][j]==1){
                    positions[i]=j;
                    break;
                }
            }
        }
        int resultantMinSwaps=0;
        for(int i=0; i<lengthOfGrid; ++i){
            int k=-1;
            for(int j=i; j<lengthOfGrid; ++j){
                if(positions[j]<=i){
                    resultantMinSwaps+=j-i;
                    k=j;
                    break;
                }
            }
            if(k!=-1){
                for(int j=k; j>i; --j){
                    int temp=positions[j];
                    positions[j]=positions[j-1];
                    positions[j-1]=temp;
                }
            } else return -1;
        }
        return resultantMinSwaps;
    }
}