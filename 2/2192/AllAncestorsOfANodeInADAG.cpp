/*
https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/?envType=daily-question&envId=2024-06-29
*/

class Solution {
public:

    void dfs(map<int, vector<int>>&parents, int curnode, vector<int>&curr){
        if(parents[curnode].size()==0) return;
        vector<int>curparent=parents[curnode];
        for(auto &vals: curparent){
            if(find(curr.begin(), curr.end(), vals)==curr.end()){
                curr.push_back(vals);
                dfs(parents, vals, curr);
            }
        }
        return;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        map<int, vector<int>>parents;
        for(auto &edge: edges){
            parents[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>>res;
        for(int i=0; i<n; ++i){
            vector<int>curr;
            dfs(parents, i, curr);
            sort(curr.begin(), curr.end());
            res.push_back(curr);
        }
        return res;
    }
};
