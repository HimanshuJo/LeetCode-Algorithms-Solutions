/*
https://leetcode.com/problems/number-of-islands/description/?envType=daily-question&envId=2024-04-19
*/

class Solution {
public:

    bool isValid(vector<vector<char>>&grid, set<pair<int, int>>&seen, int currw, int curcol){
        int rws=grid.size(), cols=grid[0].size();
        if(currw>=0&&curcol>=0&&currw<=rws-1&&curcol<=cols-1){
            if(grid[currw][curcol]=='1'){
                if(seen.find({currw, curcol})==seen.end()){
                    seen.insert({currw, curcol});
                    return true;
                }
            }
        }
        return false;
    }

    void dfs(vector<vector<char>>&grid, set<pair<int, int>>&seen, int currw, int curcol){
        if(!isValid(grid, seen, currw, curcol)) return;
        dfs(grid, seen, currw+1, curcol);
        dfs(grid, seen, currw-1, curcol);
        dfs(grid, seen, currw, curcol+1);
        dfs(grid, seen, currw, curcol-1);
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int rws=grid.size(), cols=grid[0].size(), res=0;
        set<pair<int, int>>seen;
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(grid[i][j]=='1'){
                    if(seen.find({i, j})==seen.end()){
                        res++;
                        dfs(grid, seen, i, j);
                    }
                }
            }
        }
        return res;
    }
};