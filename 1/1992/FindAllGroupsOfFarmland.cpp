/*
https://leetcode.com/problems/find-all-groups-of-farmland/description/?envType=daily-question&envId=2024-04-20
*/

class Solution {
public:

    bool isValid(vector<vector<int>>&land, int rws, int cols, set<pair<int, int>>&seen, int currw, int curcol){
        if(currw>=0&&curcol>=0&&currw<=rws-1&&curcol<=cols-1){
            if(land[currw][curcol]==1){
                if(seen.find({currw, curcol})==seen.end()) return true;
            }
        }
        return false;
    }

    void dfs(vector<vector<int>>&land, int rws, int cols, set<pair<int, int>>&seen, int currw, int curcol,
        vector<pair<int, int>>&curr){
        if(!isValid(land, rws, cols, seen, currw, curcol)) return;
        else{
            seen.insert({currw, curcol});
            curr.push_back({currw, curcol});
        }
        dfs(land, rws, cols, seen, currw+1, curcol, curr);
        dfs(land, rws, cols, seen, currw-1, curcol, curr);
        dfs(land, rws, cols, seen, currw, curcol+1, curr);
        dfs(land, rws, cols, seen, currw, curcol-1, curr);
        return;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rws=land.size(), cols=land[0].size();
        vector<vector<int>>res;
        set<pair<int, int>>seen;
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(land[i][j]==1){
                    if(seen.find({i, j})==seen.end()){
                        vector<pair<int, int>>curr;
                        dfs(land, rws, cols, seen, i, j, curr);
                        sort(curr.begin(), curr.end());
                        vector<int>currres;
                        currres.push_back(curr[0].first);
                        currres.push_back(curr[0].second);
                        currres.push_back(curr[curr.size()-1].first);
                        currres.push_back(curr[curr.size()-1].second);
                        res.push_back(currres);
                    }
                }
            }
        }
        return res;
    }
};