/*
https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/?envType=daily-question&envId=2026-01-10
*/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sz1=s1.size(), sz2=s2.size();
        vector<vector<int>>dp(sz1+1, vector<int>(sz2+1, 0));
        for(int i=sz1-1; i>=0; --i){
            dp[i][sz2]=s1[i]+dp[i+1][sz2];
        }
        for(int j=sz2-1; j>=0; --j){
            dp[sz1][j]=s2[j]+dp[sz1][j+1];
        }
        for(int i=sz1-1; i>=0; --i){
            for(int j=sz2-1; j>=0; --j){
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i+1][j+1];
                } else{
                    dp[i][j]=min(s1[i]+dp[i+1][j], s2[j]+dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};