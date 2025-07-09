/*
https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/?envType=daily-question&envId=2025-07-08
*/

class Solution {
public:

    int binarySearch(const vector<vector<int>>& events, int idx, int sz) {
        int low = idx + 1, high = sz - 1, ans = sz;
        int end = events[idx][1];
        while (low <= high) {
            int mid = (low + high) / 2;
            if (events[mid][0] > end) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>&events, int k, const int sz, int idx, vector<vector<int>>&memo){
        if(idx>=sz||k==0) return 0;
        if(memo[idx][k]!=-1) return memo[idx][k];
        int pk=0, ntpk=0;
        int nxtIdx=binarySearch(events, idx, sz);
        pk=max(pk, events[idx][2]+dfs(events, k-1, sz, nxtIdx, memo));
        ntpk=max(ntpk, dfs(events, k, sz, idx+1, memo));
        return memo[idx][k]=max(pk, ntpk);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int sz=events.size(), idx=0;
        vector<vector<int>>memo(sz+1, vector<int>(k+1, -1));
        return dfs(events, k, sz, idx, memo);
    }
};