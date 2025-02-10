/*
https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10
*/

class Solution {
public:
    string clearDigits(string s) {
        int sz=s.size();
        while(true){
            if(sz==0) break;
            bool flag=false;
            int idx=-1;
            for(int i=0; i<sz; ++i){
                if(isdigit(s[i])){
                    s[i]='#';
                    idx=i;
                    flag=true;
                    break;
                }
            }
            if(flag){
                if(idx-1>=0){
                    for(int i=idx-1; i>=0; --i){
                        if(!isdigit(s[i])){
                            s[i]='#';
                            break;
                        }
                    }
                }
            }
            if(!flag) break;
            s.erase(remove(s.begin(), s.end(), '#'), s.end());
            sz=s.size();
        }
        return s;
    }
};