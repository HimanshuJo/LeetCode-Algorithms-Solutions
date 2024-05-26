/*
https://leetcode.com/problems/student-attendance-record-ii/description/?envType=daily-question&envId=2024-05-26
*/

class Solution {
public:

    int mod=1e9+7;

    int dfs(int n, int frA, int frL, vector<vector<vector<int>>>&memo){
        if(frA>=2||frL>=3) return 0;
        if(n==0) return 1;
        if(memo[n][frA][frL]!=-1) return memo[n][frA][frL];
        int res=0;
        res+=dfs(n-1, frA, 0, memo);
        res%=mod;
        res+=dfs(n-1, frA+1, 0, memo);
        res%=mod;
        res+=dfs(n-1, frA, frL+1, memo);
        res%=mod;
        return memo[n][frA][frL]=res;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>>memo(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return dfs(n, 0, 0, memo);
    }
};