/*
https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/?envType=daily-question&envId=2025-06-26
*/

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sz=s.size(), curval=0, curpow2=1, exp=0, longestLength=0;
        for(char ch: s){
            if(ch=='0') longestLength++;
        }
        for(int i=sz-1; i>=0; --i){
            if(s[i]=='1'){
                if(curpow2<=k&&curpow2+curval<=k){
                    curval+=curpow2;
                    longestLength++;
                }
            }
            if(curpow2<=k){
                exp++;
                curpow2=pow(2, exp);
            } else break;
        }
        return longestLength;
    }
};