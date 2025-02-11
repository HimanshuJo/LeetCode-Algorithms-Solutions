/*
https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23
*/

class Solution {
public:

    void dfs(vector<vector<int>>&grid, const int rws, const int cols, set<pair<int, int>>&seen, int currw, int curcol, int &curcount){
        for(int j=0; j<cols; ++j){
            if(grid[currw][j]==1){
                auto itr=seen.find({currw, j});
                if(itr==seen.end()){
                    curcount++;
                    seen.insert({currw, j});
                    dfs(grid, rws, cols, seen, currw, j, curcount);
                }
            }
        }
        for(int i=0; i<rws; ++i){
            if(grid[i][curcol]==1){
                auto itr=seen.find({i, curcol});
                if(itr==seen.end()){
                    curcount++;
                    seen.insert({i, curcol});
                    dfs(grid, rws, cols, seen, i, curcol, curcount);
                }
            }
        }
    }

    int countServers(vector<vector<int>>& grid) {
        int rws=grid.size(), cols=grid[0].size(), res=0;
        set<pair<int, int>>seen;
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(grid[i][j]==1){
                    int curcount=1;
                    seen.insert({i, j});
                    dfs(grid, rws, cols, seen, i, j, curcount);
                    if(curcount>1)
                        res+=curcount;
                }
            }
        }
        return res;
    }
};