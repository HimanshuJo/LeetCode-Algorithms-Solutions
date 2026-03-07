/*
https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/?envType=daily-question&envId=2026-03-07
*/

class Solution {
public:
    int minFlips(string s) {
        int sz=s.length();
        auto I=[](char ch, int x)->int{
            return ch-'0'==x;
        };
        vector<vector<int>>pref(sz, vector<int>(2));
        for(int i=0; i<sz; ++i){
            pref[i][0]=(i==0?0:pref[i-1][1])+I(s[i], 1);
            pref[i][1]=(i==0?0:pref[i-1][0])+I(s[i], 0);
        }
        int res=min(pref[sz-1][0], pref[sz-1][1]);
        if(sz%2!=0){
            vector<vector<int>>suf(sz, vector<int>(2));
            for(int i=sz-1; i>=0; --i){
                suf[i][0]=(i==sz-1?0:suf[i+1][1])+I(s[i], 1);
                suf[i][1]=(i==sz-1?0:suf[i+1][0])+I(s[i], 0);
            }
            for(int i=0; i+1<sz; ++i){
                res=min(res, pref[i][0]+suf[i+1][0]);
                res=min(res, pref[i][1]+suf[i+1][1]);
            }
        }
        return res;
    }
};