/*
https://leetcode.com/problems/map-of-highest-peak/description/?envType=daily-question&envId=2025-01-22
*/

class Solution {
public:

    bool isValid(int rws, int cols, int nwrw, int nwcol){
        return nwrw>=0&&nwrw<=rws-1&&nwcol>=0&&nwcol<=cols-1;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rws=isWater.size(), cols=isWater[0].size();
        vector<vector<int>>res(rws, vector<int>(cols, -1));
        vector<vector<int>>dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>>q;
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(isWater[i][j]==1){
                    res[i][j]=0;
                    q.push({i, j});
                }
            }
        }
        int bgnHeight=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto curr=q.front();
                q.pop();
                int currw=curr.first, curcol=curr.second;
                for(auto &dir: dirs){
                    int nwrw=currw+dir[0], nwcol=curcol+dir[1];
                    if(isValid(rws, cols, nwrw, nwcol)&&res[nwrw][nwcol]==-1){
                        res[nwrw][nwcol]=bgnHeight;
                        q.push({nwrw, nwcol});
                    }
                }
            }
            bgnHeight++;
        }
        return res;
    }
};