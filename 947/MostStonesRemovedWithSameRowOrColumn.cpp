/*
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/?envType=daily-question&envId=2024-08-29
*/

class Solution {
public:

    void dfs(vector<vector<int>>&gr, set<int>&seen, int curnode){
        seen.insert(curnode);
        for(auto &nei: gr[curnode]){
            if(seen.find(nei)==seen.end()){
                dfs(gr, seen, nei);
            }
        }
        return;
    }

    int removeStones(vector<vector<int>>& stones) {
        int sz=stones.size();
        vector<vector<int>>gr(sz+1);
        for(int i=0; i<sz-1; ++i){
            for(int j=i+1; j<sz; ++j){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]){
                    gr[i].push_back(j);
                    gr[j].push_back(i);
                }
            }
        }
        set<int>seen;
        int numComponents=0;
        for(int i=0; i<sz; ++i){
            if(seen.find(i)==seen.end()){
                dfs(gr, seen, i);
                numComponents++;
            }
        }
        return sz-numComponents;
    }
};