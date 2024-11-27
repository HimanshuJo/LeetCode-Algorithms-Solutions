class Solution {
public:

    int dijkstra(int n, vector<vector<int>>&gr, int currentSource, int currentDestination){
        gr[currentSource].push_back(currentDestination);
        vector<int>minDists(n, INT_MAX);
        minDists[0]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int sz=pq.size();
            while(sz--){
                auto curr=pq.top();
                pq.pop();
                int curval=curr.first, curnode=curr.second;
                for(auto &nei: gr[curnode]){
                    int curnwdist=minDists[curnode]+1;
                    if(curnwdist<minDists[nei]){
                        minDists[nei]=curnwdist;
                        pq.push({curnwdist, nei});
                    }
                }
            }
        }
        return minDists[n-1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>gr(n);
        for(int i=0; i<n; ++i){
            if(i==n-1) break;
            gr[i].push_back(i+1);
        }
        vector<int>res;
        for(auto &query: queries){
            int currentsrc=query[0], currentdest=query[1];
            int curmindist=dijkstra(n, gr, currentsrc, currentdest);
            res.push_back(curmindist);
        }
        return res;
    }
};
