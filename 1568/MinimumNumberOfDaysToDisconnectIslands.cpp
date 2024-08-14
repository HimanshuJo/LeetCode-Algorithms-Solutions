/*
https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/?envType=daily-question&envId=2024-08-11
*/

class Solution {
public:

    vector<vector<int>>dirs={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isValid(vector<vector<int>>&grid, set<pair<int, int>>&seen, const int currw, const int curcol){
        const int rws=grid.size(), cols=grid[0].size();
        if(currw>=0&&curcol>=0&&currw<=rws-1&&curcol<=cols-1){
            if(grid[currw][curcol]==1){
                return seen.find({currw, curcol})==seen.end();
            }
        }
        return false;
    }

    void dfs(vector<vector<int>>&grid, set<pair<int, int>>&seen, int currw, int curcol){
        seen.insert({currw, curcol});
        for(auto &dir: dirs){
            int nwrw=currw+dir[0], nwcol=curcol+dir[1];
            if(isValid(grid, seen, nwrw, nwcol)){
                dfs(grid, seen, nwrw, nwcol);
            }
        }
        return;
    }

    int countI(vector<vector<int>>&grid){
        int rws=grid.size(), cols=grid[0].size();
        int numIslands=0;
        set<pair<int, int>>seen;
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(seen.find({i, j})==seen.end()&&grid[i][j]==1){
                    dfs(grid, seen, i, j);
                    numIslands++;
                }
            }
        }
        return numIslands;
    }

    int minDays(vector<vector<int>>& grid) {
        const int rws=grid.size(), cols=grid[0].size();
        int countIslands=countI(grid);
        if(countIslands!=1) return 0;
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int countNwIslands=countI(grid);
                    if(countNwIslands!=1) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};