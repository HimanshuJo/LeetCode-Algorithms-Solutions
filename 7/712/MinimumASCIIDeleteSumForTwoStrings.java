/*
https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/?envType=daily-question&envId=2026-01-10
*/

class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int lengthOfS1=s1.length(), lengthOfS2=s2.length();
        int[][]dp=new int[lengthOfS1+1][lengthOfS2+1];
        for(int i=0; i<=lengthOfS1; ++i){
            for(int j=0; j<=lengthOfS2; ++j){
                dp[i][j]=0;
            }
        }
        for(int i=lengthOfS1-1; i>=0; --i){
            dp[i][lengthOfS2]=s1.charAt(i)+dp[i+1][lengthOfS2];
        }
        for(int j=lengthOfS2-1; j>=0; --j){
            dp[lengthOfS1][j]=s2.charAt(j)+dp[lengthOfS1][j+1];
        }
        for(int i=lengthOfS1-1; i>=0; --i){
            for(int j=lengthOfS2-1; j>=0; --j){
                if(s1.charAt(i)==s2.charAt(j)){
                    dp[i][j]=dp[i+1][j+1];
                } else{
                    dp[i][j]=Math.min(s1.charAt(i)+dp[i+1][j], s2.charAt(j)+dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
}