/*
https://leetcode.com/problems/flip-square-submatrix-vertically/description/?envType=daily-question&envId=2026-03-21
*/

class Solution {
    public int[][] reverseSubmatrix(int[][] grid, int x, int y, int k) {
        Stack<ArrayList<Integer>>stkOfList=new Stack<>();
        int rows=grid.length, columns=grid[0].length;
        int maxRowsToTraverse=x+k-1, maxColumnsToTraverse=y+k-1;
        for(int i=x; i<=maxRowsToTraverse; ++i){
            ArrayList<Integer>currentList=new ArrayList<>();
            for(int j=y; j<=maxColumnsToTraverse; ++j){
                currentList.add(grid[i][j]);
            }
            stkOfList.add(currentList);
        }
        for(int i=x; i<=maxRowsToTraverse; ++i){
            ArrayList<Integer>currentList=stkOfList.pop();
            int beginIndex=0;
            for(int j=y; j<=maxColumnsToTraverse; ++j){
                grid[i][j]=currentList.get(beginIndex++);
            }
        }
        return grid;
    }
}