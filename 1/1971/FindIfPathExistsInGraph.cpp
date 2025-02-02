/*
https://leetcode.com/problems/find-if-path-exists-in-graph/description/?envType=daily-question&envId=2024-04-21
*/

class Solution {
public:

    void dfs(int source, int destination, vector<vector<int>>&gr, set<int>&seen, bool &flag){
        if(source==destination){
            flag=true;
            return;
        }
        for(auto &nei: gr[source]){
            if(seen.find(nei)==seen.end()){
                seen.insert(nei);
                dfs(nei, destination, gr, seen, flag);
            }
        }
        return;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>gr(n);
        int sz=edges.size();
        for(int i=0; i<sz; ++i){
            gr[edges[i][0]].push_back(edges[i][1]);
            gr[edges[i][1]].push_back(edges[i][0]);
        }
        set<int>seen;
        bool flag=false;
        seen.insert(source);
        dfs(source, destination, gr, seen, flag);
        return flag;
    }
};