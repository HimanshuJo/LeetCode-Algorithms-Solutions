/*
https://leetcode.com/problems/task-scheduler/description/?envType=daily-question&envId=2024-03-19
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<int, int>mp;
        for(auto &tsks: tasks){
            mp[tsks]++;
        }
        priority_queue<int, vector<int>>pq;
        for(auto &entries: mp){
            pq.push(entries.second);
        }
        int res=0;
        while(!pq.empty()){
            vector<int>curcooldwn;
            for(int i=0; i<=n; ++i){
                if(!pq.empty()){
                    curcooldwn.push_back(pq.top()-1);
                    pq.pop();
                }
            }
            for(auto &vals: curcooldwn){
                if(vals>0){
                    pq.push(vals);
                }
            }
            res+=pq.empty()?curcooldwn.size():n+1;
        }
        return res;
    }
};