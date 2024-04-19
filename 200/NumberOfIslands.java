/*
https://leetcode.com/problems/number-of-islands/description/?envType=daily-question&envId=2024-04-19
*/

class Solution {

    public boolean isValid(char[][] grid, HashSet<String>seen, int currw, int curcol){
        int rws=grid.length, cols=grid[0].length;
        if(currw>=0&&curcol>=0&&currw<=rws-1&&curcol<=cols-1){
            if(grid[currw][curcol]=='1'){
                String tochk=String.valueOf(currw)+"#"+String.valueOf(curcol);
                if(!seen.contains(tochk)){
                    seen.add(tochk);
                    return true;
                }
            }
        }
        return false;
    }

    public void dfs(char[][] grid, HashSet<String>seen, int currw, int curcol){
        if(!isValid(grid, seen, currw, curcol)) return;
        dfs(grid, seen, currw+1, curcol);
        dfs(grid, seen, currw-1, curcol);
        dfs(grid, seen, currw, curcol+1);
        dfs(grid, seen, currw, curcol-1);
        return;
    }

    public int numIslands(char[][] grid) {
        int rws=grid.length, cols=grid[0].length, res=0;
        HashSet<String>seen=new HashSet<>();
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(grid[i][j]=='1'){
                    if(!seen.contains(String.valueOf(i)+"#"+String.valueOf(j))){
                        res++;
                        dfs(grid, seen, i, j);
                    }
                }
            }
        }
        return res;
    }
}