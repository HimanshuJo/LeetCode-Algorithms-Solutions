/*
https://leetcode.com/problems/count-days-without-meetings/description/?envType=daily-question&envId=2025-03-24
*/

class Solution1 {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        unordered_map<int, int>countsMp;
        int sz=meetings.size(), res=0;
        for(int i=0; i<sz; ++i){
            int bgn=meetings[i][0], end=meetings[i][1];
            for(int j=bgn; j<=end; ++j){
                countsMp[j]++;
            }
        }
        for(int i=1; i<=days; ++i){
            if(countsMp.find(i)==countsMp.end()) res++;
        }
        return res;
    }
};

/*
Time Complexity: O(N⋅log(N))
Space complexity: O(log⁡⁡N) or O(N)
*/
class Solution_optimal {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int sz=meetings.size(), latestEnd=0, freeDays=0;
        for(int i=0; i<sz; ++i){
            int curbgn=meetings[i][0], curend=meetings[i][1];
            if(curbgn>latestEnd){
                freeDays+=curbgn-(latestEnd+1);
            }
            latestEnd=max(latestEnd, curend);
        }
        freeDays+=days-latestEnd;
        return freeDays;
    }
};
