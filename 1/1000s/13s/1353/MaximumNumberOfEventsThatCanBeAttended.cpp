/*
https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/?envType=daily-question&envId=2025-07-07
*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>>pq;
        int sz=events.size(), idx=0, maxDay=0, res=0;
        for(auto &event: events){
            maxDay=max(maxDay, event[1]);
        }
        for(int curDay=1; curDay<=maxDay; ++curDay){
            while(idx<sz&&events[idx][0]==curDay){
                pq.push(events[idx++][1]);
            }
            while(!pq.empty()&&pq.top()<curDay){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                res++;
            }
        }
        return res;
    }
};