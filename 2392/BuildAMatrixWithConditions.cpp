/*
https://leetcode.com/problems/build-a-matrix-with-conditions/description/?envType=daily-question&envId=2024-07-21
*/

class Solution {
public:

    void dfs(bool &hasCycle, vector<vector<int>>&gr, vector<int>&curOrder, vector<int>&currentlyVisited, int curVertex){
        currentlyVisited[curVertex]=1;
        for(auto &nei: gr[curVertex]){
            if(currentlyVisited[nei]==0){
                dfs(hasCycle, gr, curOrder, currentlyVisited, nei);
                if(hasCycle) return;
            } else if(currentlyVisited[nei]==1){
                hasCycle=true;
                return;
            }
        }
        currentlyVisited[curVertex]=2;
        curOrder.push_back(curVertex);
    }

    vector<int> topoSort(int vertices, vector<vector<int>>&edges, bool &hasCycle){
        vector<vector<int>>gr(vertices+1);
        for(auto &edg: edges){
            gr[edg[0]].push_back(edg[1]);
        }
        vector<int>curOrder;
        vector<int>currentlyVisited(vertices+1, 0);
        for(int i=1; i<=vertices; ++i){
            if(currentlyVisited[i]==0){
                dfs(hasCycle, gr, curOrder, currentlyVisited, i);
                if(hasCycle) return {};
            }
        }
        reverse(curOrder.begin(), curOrder.end());
        return curOrder;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>rowOrder, colOrder;
        bool hasCycle=false;
        rowOrder=topoSort(k, rowConditions, hasCycle);
        if(hasCycle) return {};
        colOrder=topoSort(k, colConditions, hasCycle);
        if(hasCycle) return {};
        vector<vector<int>>res(k, vector<int>(k, 0));
        for(int i=0; i<k; ++i){
            for(int j=0; j<k; ++j){
                if(rowOrder[i]==colOrder[j]){
                   res[i][j]=rowOrder[i]; 
                }
            }
        }
        return res;
    }
};