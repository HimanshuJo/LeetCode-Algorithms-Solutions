/*
https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=daily-question&envId=2026-03-05
*/

class Solution {
public:

    bool isValid(string &str){
        int sz=str.size(), idx=0;
        char curr=str[0];
        for(int i=1; i<sz; ++i){
            char nxt=str[i];
            if(nxt==curr) return false;
            curr=nxt;
        }
        return true;
    }

    int minOperations(string s) {
        int sz=s.size(), idx=0, count1=0, count2=0, res=INT_MAX;
        string tmp1=s, tmp2=s;
        if(tmp1[idx]!='0'){
            tmp1[idx]='0';
            count1++;
        }
        char prev=tmp1[idx];
        for(int i=1; i<sz; ++i){
            if(isValid(tmp1)){
                res=min(res, count1);
                break;
            }
            if(tmp1[i]==prev){
                if(prev=='0'){
                    tmp1[i]='1';
                } else tmp1[i]='0';
                count1++;
            }
            prev=tmp1[i];
        }
        if(isValid(tmp1)){
            res=min(res, count1);
        }
        idx=0;
        if(tmp2[idx]!='1'){
            tmp2[idx]='1';
            count2++;
        }
        prev=tmp2[idx];
        for(int i=1; i<sz; ++i){
            if(isValid(tmp2)){
                res=min(res, count2);
                break;
            }
            if(tmp2[i]==prev){
                if(prev=='0'){
                    tmp2[i]='1';
                } else tmp2[i]='0';
                count2++;
            }
            prev=tmp2[i];
        }
        if(isValid(tmp2)){
            res=min(res, count2);
        }
        return res;
    }
};