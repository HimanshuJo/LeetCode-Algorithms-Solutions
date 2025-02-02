/*
https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/?envType=daily-question&envId=2024-06-03
*/

class Solution {
public:
    int appendCharacters(string s, string t) {
        int res=0, sz1=s.size(), sz2=t.size(), curidx=-1;
        for(int i=0; i<sz2; ++i){
            char curr=t[i];
            bool flag=false;
            if(curidx+1<=sz1-1){
                for(int j=curidx+1; j<sz1; ++j){
                    if(s[j]==curr){
                        flag=true;
                        curidx=j;
                        break;
                    }
                }
            }
            if(!flag){
                res+=(sz2-i);
                break;
            }
        }
        return res;
    }
};