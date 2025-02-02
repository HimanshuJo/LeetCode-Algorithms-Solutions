/*
https://leetcode.com/problems/island-perimeter/description/?envType=daily-question&envId=2024-04-18
*/

class Solution {
public:

    int bfs(vector<vector<int>>&grid, int rws, int cols, int strtrw, int strtcol){
        queue<pair<int, int>>q;
        q.push({strtrw, strtcol});
        set<pair<int, int>>seen;
        seen.insert({strtrw, strtcol});
        vector<vector<int>>dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int res=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto curr=q.front();
                q.pop();
                int currw=curr.first, curcol=curr.second;
                for(auto &dir: dirs){
                    int nwrw=currw+dir[0], nwcol=curcol+dir[1];
                    if(nwrw<0||nwrw>=rws||nwcol<0||nwcol>=cols) res++;
                    else if(grid[nwrw][nwcol]==0) res++;
                    else if(grid[nwrw][nwcol]==1){
                        if(seen.find({nwrw, nwcol})==seen.end()){
                            seen.insert({nwrw, nwcol});
                            q.push({nwrw, nwcol});
                        }
                    }
                }
            }
        }
        return res;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int rws=grid.size(), cols=grid[0].size();
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(grid[i][j]==1){
                    return bfs(grid, rws, cols, i, j);
                }
            }
        }
        return 0;
    }
};