/*
https://leetcode.com/problems/count-and-say/description/?envType=daily-question&envId=2025-04-18
*/

class Solution {
public:

    string res="";

    string createNwStr(string &bgn){
        string nw="";
        int sz=bgn.size(), i=0;
        while(true){
            if(i>=sz) break;
            char curr=bgn[i];
            int count=1;
            while(true){
                if(i>=sz) break;
                if(i+1<=sz-1){
                    char nxt=bgn[i+1];
                    if(nxt!=curr){
                        nw+=to_string(count);
                        nw+=curr;
                        ++i;
                        break;  
                    } else{
                        count++;
                        ++i;
                    }
                } else{
                    nw+=to_string(count);
                    nw+=curr;
                    ++i;
                    break;
                }
            }
        }
        return nw;
    }

    void dfs(int n, string &bgn){
        if(n==0){
            res=bgn;
            return;
        }
        string nxt=createNwStr(bgn);
        dfs(n-1, nxt);
        return;
    }

    string countAndSay(int n) {
        string bgn="1";
        dfs(n-1, bgn);
        return res;
    }
};