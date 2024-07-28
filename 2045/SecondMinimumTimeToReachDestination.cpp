/*
https://leetcode.com/problems/second-minimum-time-to-reach-destination/?envType=daily-question&envId=2024-07-28
*/

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>gr(n+1);
        for(auto &edge: edges){
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        vector<int>dist1(n+1, INT_MAX), dist2(n+1, INT_MAX), freq(n+1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        dist1[1]=0;
        pq.push({0, 1});
        while(!pq.empty()){
            int sz=pq.size();
            while(sz--){
                auto curr=pq.top();
                pq.pop();
                int timetaken=curr.first, node=curr.second;
                freq[node]++;
                if(node==n&&freq[node]==2) return timetaken;
                if((timetaken/change)%2!=0){
                    timetaken=change*(timetaken/change+1)+time;
                } else timetaken+=time;
                for(auto &nei: gr[node]){
                    if(freq[nei]==2) continue;
                    if(dist1[nei]>timetaken){
                        dist2[nei]=dist1[nei];
                        dist1[nei]=timetaken;
                        pq.push({timetaken, nei});
                    } else if(dist2[nei]>timetaken&&dist1[nei]!=timetaken){
                        dist2[nei]=timetaken;
                        pq.push({timetaken, nei});
                    }
                }
            }
        }
        return 0;
    }
};