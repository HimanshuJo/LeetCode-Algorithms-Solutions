/*
https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/?envType=daily-question&envId=2026-03-06
*/

class Solution {
public:

    bool checkOnesSegment(string s) {
        int sz=s.length();
        if(sz==1&&s[0]=='1') return true;
        vector<string>all;
        int idx=0;
        string tmp="";
        while(true){
            if(idx>=sz) break;
            char curr=s[idx];
            if(curr=='1'){
                while(true){
                    if(s[idx]!='1') break;
                    tmp+=s[idx];
                    idx++;
                }
                if(tmp.size()>=1){
                    all.push_back(tmp);
                    tmp="";
                }
            } else idx++;
        }
        return all.size()==1;
    }
};