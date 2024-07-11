/*
https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11
*/

class Solution {
public:
    string reverseParentheses(string s) {
        int sz=s.size();
        while(true){
            int idx1=0, idx2=0;
            string tofrm="";
            bool flag=false;
            while(true){
                if(s[idx1]==')'){
                    flag=true;
                    s[idx1]='#';
                    idx1--;
                    idx2=idx1;
                    bool secflag=false;
                    while(true){
                        if(s[idx2]=='(') break;
                        idx2--;
                        if(idx2<0){
                            secflag=true;
                            break;
                        }
                    }
                    if(!secflag){
                        s[idx2]='#';
                        idx2++;
                        for(int i=idx1; i>=idx2; --i){
                            tofrm+=s[i];
                        }
                        int nwidx=0;
                        for(int i=idx2; i<=idx1; ++i){
                            s[i]=tofrm[nwidx++];
                        }
                        break;
                    } else break;
                }
                idx1++;
                if(idx1>=sz) break;
            }
            if(!flag) break;
            s.erase(remove(s.begin(), s.end(), '#'), s.end());
        }
        return s;
    }
};