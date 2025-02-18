/*
https://leetcode.com/problems/construct-smallest-number-from-di-string/description/?envType=daily-question&envId=2025-02-18
*/

class Solution {
public:

    bool isValid(string &pattern, string &str){
        int sz=pattern.size();
        for(int i=0; i<sz; ++i){
            if(pattern[i]=='I'){
                if(str[i]-'0'>str[i+1]-'0') return false;
            } else{
                if(str[i]-'0'<str[i+1]-'0') return false;
            }
        }
        return true;
    }

    void dfs(string &pattern, int sz, string curr, vector<string>&all, vector<bool>&seen){
        if(curr.size()==sz+1){
            if(isValid(pattern, curr)){
                all.push_back(curr);
            }
            return;
        }
        for(int i=1; i<=sz+1; ++i){
            if(!seen[i]){
                seen[i]=true;
                curr+=to_string(i);
                dfs(pattern, sz, curr, all, seen);
                curr.pop_back();
                seen[i]=false;
            }
        }
        return;
    }

    vector<string> genAllPatterns(string &pattern){
        int sz=pattern.size();
        string curr="";
        vector<string>all;
        vector<bool>seen(sz+2, false);
        dfs(pattern, sz, curr, all, seen);
        return all;
    }

    string smallestNumber(string pattern) {
        vector<string>all=genAllPatterns(pattern);
        sort(all.begin(), all.end());
        return all[0];
    }
};