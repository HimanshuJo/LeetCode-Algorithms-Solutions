/*
https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2025-12-23
*/

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int sz=events.size(), res=INT_MIN;
        for(int i=0; i<sz; ++i){
            res=max(res, events[i][2]);
        }
        vector<int>best(sz+1, 0);
        for(int i=sz-1; i>=0; --i){
            best[i]=max(best[i+1], events[i][2]);
        }
        for(int i=0; i<sz; ++i){
            int curbegin=events[i][0], curend=events[i][1], curval=events[i][2];
            int l=i+1, r=sz;
            while(l<r){
                int mid=l+(r-l)/2;
                if(events[mid][0]>curend){
                    r=mid;
                } else l=mid+1;
            }
            res=max(res, curval+best[l]);
        }
        return res;
    }
};