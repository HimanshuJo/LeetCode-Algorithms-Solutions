/*
https://leetcode.com/problems/path-with-maximum-probability/description/?envType=daily-question&envId=2024-08-31
*/

class Solution {
public:

    double djikstra(int n, vector<vector<int>>&edges, vector<double>&succProb, int start_node, int end_node,
                    vector<vector<int>>&gr, map<pair<int, int>, double>&mp){
        priority_queue<pair<double, int>, vector<pair<double, int>>>pq;
        pq.push({1.0, start_node});
        vector<double>maxProbs(n+1, 0.0);
        maxProbs[start_node]=1.0;
        while(!pq.empty()){
            int sz=pq.size();
            while(sz--){
                auto curr=pq.top();
                pq.pop();
                if(curr.second==end_node) return curr.first;
                for(auto &nei: gr[curr.second]){
                    double nwProb=curr.first*mp[{curr.second, nei}];
                    if(nwProb>maxProbs[nei]){
                        maxProbs[nei]=nwProb;
                        pq.push({nwProb, nei});
                    }
                }
            }
        }
        return 0.0;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<int>>gr(n);
        map<pair<int, int>, double>mp;
        int idx=0;
        for(auto &edge: edges){
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
            mp[{edge[0], edge[1]}]=succProb[idx];
            mp[{edge[1], edge[0]}]=succProb[idx++];
        }
        return djikstra(n, edges, succProb, start_node, end_node, gr, mp);
    }
};